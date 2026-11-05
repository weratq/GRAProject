// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestPrediction.h"

// Sets default values
AMyTestPrediction::AMyTestPrediction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	

}

void AMyTestPrediction::MoveFWD_Implementation(bool isFWD)
{
	SetActorLocation(GetActorLocation() + (isFWD ? GetActorForwardVector() : GetActorForwardVector() * -1) * Speed * GetWorld()->GetDeltaSeconds());
}

void AMyTestPrediction::MoveRight_Implementation(bool isRight)
{
	SetActorLocation(GetActorLocation() + (isRight ? GetActorRightVector() : GetActorRightVector() * -1) * Speed * GetWorld()->GetDeltaSeconds());
}

void AMyTestPrediction::C_MoveForward(bool isFWD)
{
	
	SetActorLocation(GetActorLocation() + (isFWD ? GetActorForwardVector() : GetActorForwardVector() * -1) * Speed * GetWorld()->GetDeltaSeconds());
	
	MoveFWD(isFWD);
}

void AMyTestPrediction::C_MoveRight(bool isRight)
{
	SetActorLocation(GetActorLocation() + (isRight ? GetActorRightVector() : GetActorRightVector() * -1) * Speed * GetWorld()->GetDeltaSeconds());
	
	MoveRight(isRight);
}

// Called when the game starts or when spawned
void AMyTestPrediction::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTestPrediction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

