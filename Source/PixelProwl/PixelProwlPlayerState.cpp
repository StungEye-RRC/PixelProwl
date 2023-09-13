// Fill out your copyright notice in the Description page of Project Settings.


#include "PixelProwlPlayerState.h"
#include "Logging/StructuredLog.h"

int32 APixelProwlPlayerState::UpdateScore(int32 ScoreDelta) {
	SetScore(GetScore() + ScoreDelta);
	OnScoreChangedDelegate.Broadcast(GetScore());
	UE_LOGFMT(LogTemp, Warning, "Delta: {0} Score: {1}", ScoreDelta, GetScore());
	return GetScore();
}
