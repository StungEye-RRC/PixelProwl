// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "Components/TextBlock.h"
#include "../PixelProwlPlayerState.h"

bool UPlayerHUD::Initialize() {

	APixelProwlPlayerState* PlayerState = GetOwningPlayerState<APixelProwlPlayerState>();

	PlayerState->OnScoreChangedDelegate.AddUniqueDynamic(this, &UPlayerHUD::OnScoreChanged);
	
	return Super::Initialize();
}

void UPlayerHUD::OnScoreChanged(int32 NewScore) {
	Score->SetText(FText::AsNumber(NewScore));
}

void UPlayerHUD::NativeConstruct() {
	Super::NativeConstruct();

	if (Score) {
		Score->SetText(FText::FromString(TEXT("0")));
	}
}
