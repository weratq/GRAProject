// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "MyTestPrediction.generated.h"

UCLASS()
class GRAPROJECT_API AMyTestPrediction : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTestPrediction();
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float Speed;
	
	UFUNCTION(BlueprintCallable, Server, Unreliable)
	void MoveFWD(bool isFWD);
	UFUNCTION(BlueprintCallable, Server, Unreliable)
	void MoveRight(bool isRight);
	
	UFUNCTION(BlueprintCallable)
	void C_MoveForward(bool isFWD);
	UFUNCTION(BlueprintCallable)
	void C_MoveRight(bool isRight);
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
