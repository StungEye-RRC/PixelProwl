// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayPauseMenu.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Logging/StructuredLog.h"
#include "PixelProwl/PixelProwlGameInstance.h"
#include "PixelProwl/PixelProwlPlayerState.h"

void UPlayPauseMenu::NativeConstruct() {
	Super::NativeConstruct();
	
	GameInstance = Cast<UPixelProwlGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	GameInstance->SetInputMode(false);

	if (QuitButton) {
		QuitButton->OnClicked.AddDynamic(this, &UPlayPauseMenu::OnQuit);
	}

	if (PlayPauseButton) {
		PlayPauseButton->OnClicked.AddDynamic(this, &UPlayPauseMenu::OnPlayPause);
	}

	if (FinalScore) {
		FinalScore->SetVisibility(ESlateVisibility::Hidden);
	}
	
	APixelProwlPlayerState* PlayerState = GetOwningPlayerState<APixelProwlPlayerState>();
	if (PlayerState) {
		PlayerState->OnTimerEndDelegate.AddUniqueDynamic(this, &UPlayPauseMenu::OnTimerEnd);
	}
}

void UPlayPauseMenu::OnQuit() {
	UE_LOGFMT(LogTemp, Warning, "On Quit");
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}

void UPlayPauseMenu::OnTimerEnd(int32 Score) {
	UE_LOGFMT(LogTemp, Warning, "Timer has ended.");
	GameIsOver = true;
	OnPlayPause();
	if (FinalScore) {
		FinalScore->SetText(FText::AsNumber(Score));
		FinalScore->SetVisibility(ESlateVisibility::Visible);
	}
}

void UPlayPauseMenu::OnPlayPause() {
	UE_LOGFMT(LogTemp, Warning, "On Play/Pause");
	GameIsPaused = !GameIsPaused;
	GameInstance->SetInputMode(!GameIsPaused);

	if (GameIsPaused) {
		SetVisibility(ESlateVisibility::Visible);
	} else {
		SetVisibility(ESlateVisibility::Hidden);
		if (GameIsOver) {
			GameIsOver = false;
		}
	}

	if (PlayPauseText) {
		if (GameIsOver) 
			PlayPauseText->SetText(FText::FromString(TEXT("Restart")));
		else
			PlayPauseText->SetText(FText::FromString(TEXT("Resume")));
	}
}
