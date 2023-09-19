// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PixelProwlPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChangedSignature, int32, NewScore);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimerChangedSignature, FString, NewTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimerEndSignature, int32, FinalScore);
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

	UPROPERTY(BlueprintAssignable)
	FOnTimerChangedSignature OnTimerChangedDelegate;

	UPROPERTY()
	FOnTimerEndSignature OnTimerEndDelegate;

	UPROPERTY(BlueprintReadOnly, Category = "Countdown Timer")
	int32 Minutes = 0;
	
	UPROPERTY(BlueprintReadOnly, Category = "Countdown Timer")
	int32 Seconds = 10;

	UPROPERTY()
	FTimerHandle CountDownTimerHandle;
	
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void CountDown();

	void broadcastTimer();
};
