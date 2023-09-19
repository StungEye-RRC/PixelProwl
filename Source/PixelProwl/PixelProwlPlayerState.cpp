// Fill out your copyright notice in the Description page of Project Settings.


#include "PixelProwlPlayerState.h"
#include "Logging/StructuredLog.h"

int32 APixelProwlPlayerState::UpdateScore(int32 ScoreDelta) {
	SetScore(GetScore() + ScoreDelta);
	OnScoreChangedDelegate.Broadcast(GetScore());
	UE_LOGFMT(LogTemp, Warning, "Delta: {0} Score: {1}", ScoreDelta, GetScore());
	return GetScore();
}

void APixelProwlPlayerState::BeginPlay() {
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(CountDownTimerHandle, this, &APixelProwlPlayerState::CountDown, 1.0f, true );
	OnTimerChangedDelegate.Broadcast(FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds));
}

void APixelProwlPlayerState::CountDown() {
	Seconds--;	
	if (Seconds < 0)  {
		Seconds = 59;
		Minutes--;
	}

	OnTimerChangedDelegate.Broadcast(FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds));
}
