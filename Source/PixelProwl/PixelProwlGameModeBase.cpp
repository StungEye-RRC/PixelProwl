// Copyright Epic Games, Inc. All Rights Reserved.


#include "PixelProwlGameModeBase.h"
#include "PixelProwlGameInstance.h"
#include "Actors/PlayerCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/StructuredLog.h"
#include "UI/PlayPauseMenu.h"

void APixelProwlGameModeBase::BeginPlay()
{
	Super::BeginPlay(); 
	UE_LOGFMT(LogTemp, Warning, "Hello from C++ from Game Mode.");
	
	PlayerController = UGameplayStatics::GetPlayerControllerFromID(GetWorld(), 0);
	PlayerController->SetPause(true); // Game starts paused. Game Instance will unpause.

	PlayerCharacter = Cast<APlayerCharacter>(PlayerController->GetPawn());
	
	GameInstance = Cast<UPixelProwlGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	
	if (DefaultHUDWidget) {
		HUDWidget = CreateWidget<UUserWidget>(GetWorld(), DefaultHUDWidget);
		HUDWidget->AddToViewport();
	} else {
		UE_LOGFMT(LogTemp, Error, "No HUD widget specified in Game Mode Blueprint.");
	}	

	if (DefaultPlayPauseWidget) {
		PlayPauseWidget = CreateWidget<UUserWidget>(GetWorld(), DefaultPlayPauseWidget);
		PlayPauseWidget->AddToViewport();
		PlayerCharacter->SetMenuWidget(Cast<UPlayPauseMenu>(PlayPauseWidget));
	} else {
		UE_LOGFMT(LogTemp, Error, "No Play/Pause widget specified in Game Mode Blueprint.");
	}
}
