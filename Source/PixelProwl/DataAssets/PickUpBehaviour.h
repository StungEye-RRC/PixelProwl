// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PixelProwl/Actors/PlayerCharacter.h"
#include "UObject/Object.h"
#include "PickUpBehaviour.generated.h"

class UPickUpDataAsset;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class PIXELPROWL_API UPickUpBehaviour : public UObject {
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent)
	void Behaviour(APlayerCharacter* PlayerCharacter, UPickUpDataAsset* DataAsset);
};
