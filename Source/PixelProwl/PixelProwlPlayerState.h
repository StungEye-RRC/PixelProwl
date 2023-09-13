// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PixelProwlPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChangedSignature, int32, NewScore);

/**
 * 
 */
UCLASS()
class PIXELPROWL_API APixelProwlPlayerState : public APlayerState {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Score")
	int32 UpdateScore(int32 ScoreDelta);

	UPROPERTY(BlueprintAssignable)
	FOnScoreChangedSignature OnScoreChangedDelegate;
};
