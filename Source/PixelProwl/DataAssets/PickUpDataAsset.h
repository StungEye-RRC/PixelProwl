// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NiagaraSystem.h"
#include "PickUpDataAsset.generated.h"

class UPickUpBehaviour;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType) // Important!
class PIXELPROWL_API UPickUpDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Points;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UNiagaraSystem* Particles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UPickUpBehaviour>> Behaviours;
};
