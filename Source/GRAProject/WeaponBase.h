// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"


USTRUCT(BlueprintType)
struct FWeaponInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText WeaponName;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UTexture2D> Texture;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UStaticMesh> Mesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Damage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AttackSpeed;
};


class UDataTable;

UCLASS(Blueprintable)
class GRAPROJECT_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();
	
	UFUNCTION(BlueprintCallable)
	void UpdateWeapon(FName NewRowName);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Damage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AttackSpeed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* Texture;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(ExposeOnSpawn = true))
	FName RowName;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* DataTable;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* MeshComponent;
	
	UFUNCTION()
	void OnMeshLoad(UObject* LoadedMesh);

};
