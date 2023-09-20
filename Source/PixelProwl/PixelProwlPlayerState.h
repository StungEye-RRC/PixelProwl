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

	static constexpr int32 TimerSeconds{0};
	static constexpr int32 TimerMinutes{2};

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
	int32 Minutes;
	
	UPROPERTY(BlueprintReadOnly, Category = "Countdown Timer")
	int32 Seconds;

	UPROPERTY()
	FTimerHandle CountDownTimerHandle;
	
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UFUNCTION()
	void CountDown();
	
	void BroadcastTimer();
	void ResetState();
};
