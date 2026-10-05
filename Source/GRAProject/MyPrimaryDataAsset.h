// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MyPrimaryDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GRAPROJECT_API UMyPrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
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
	
	
	FPrimaryAssetId GetPrimaryAssetId() const override { return FPrimaryAssetId("MyAssetType", GetFName()); } 

};
