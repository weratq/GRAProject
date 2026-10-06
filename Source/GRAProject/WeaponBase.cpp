// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"



void AWeaponBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWeaponBase, RowName);
}


// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");

}

void AWeaponBase::UpdateWeapon(FName NewRowName)
{
	RowName = NewRowName;
	if (RowName.IsEqual("") && !IsValid(DataTable))
	{
		UE_LOG(LogTemp, Error,TEXT("TableData not valid"));
		return;
	}
	FString ContextString;
	FWeaponInfo* CurrWeaponInfo = DataTable->FindRow<FWeaponInfo>(RowName,ContextString);
	if (CurrWeaponInfo!=nullptr)
	{
		Damage = CurrWeaponInfo->Damage;
		AttackSpeed = CurrWeaponInfo->AttackSpeed;
;		CurrWeaponInfo->Mesh.LoadAsync(FLoadSoftObjectPathAsyncDelegate::CreateLambda([this](const FSoftObjectPath&, UObject* InLoadedObject)
			{
				this->OnMeshLoad(InLoadedObject);
			}));
		CurrWeaponInfo->Texture.LoadAsync(FLoadSoftObjectPathAsyncDelegate::CreateLambda([this](const FSoftObjectPath&, UObject* InLoadedObject)
		{
			this->Texture = Cast<UTexture2D>(InLoadedObject);
		}));
		//MeshComponent->SetStaticMesh(CurrWeaponInfo->Mesh);
	}
}



// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	UpdateWeapon(RowName);
	
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponBase::OnRep_Health_Implementation(FName NewRowName)
{
	
}

void AWeaponBase::OnMeshLoad(UObject* LoadedMesh)
{
	if (IsValid(LoadedMesh))
	{
		UStaticMesh* StaticMesh = Cast<UStaticMesh>(LoadedMesh);
		if (IsValid(StaticMesh))
		{
			MeshComponent->SetStaticMesh(StaticMesh);
		}
	}
}

