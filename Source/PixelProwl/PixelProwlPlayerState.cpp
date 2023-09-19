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
	broadcastTimer();
}

void APixelProwlPlayerState::CountDown() {
	Seconds--;
	
	if (Seconds < 0)  {
		Seconds = 59;
		Minutes--;
	}

	if (Seconds == 0 && Minutes == 0) {
		// GetWorldTimerManager().ClearTimer(CountDownTimerHandle);
		OnTimerEndDelegate.Broadcast(GetScore());
		SetScore(0);
		Seconds = 0;
		Minutes = 5;
		OnScoreChangedDelegate.Broadcast(GetScore());
	}
	broadcastTimer();
}

void APixelProwlPlayerState::broadcastTimer() {
	OnTimerChangedDelegate.Broadcast(FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds));
}
