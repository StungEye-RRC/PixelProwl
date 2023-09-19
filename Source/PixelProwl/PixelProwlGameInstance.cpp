// Fill out your copyright notice in the Description page of Project Settings.


#include "PixelProwlGameInstance.h"

void UPixelProwlGameInstance::SetInputMode(bool GameOnly) const {
	const UWorld* World = GetWorld();
	if (!World) {
		return;
	}

	if (APlayerController* const Controller = World->GetFirstPlayerController()) {
		if (GameOnly) {
			const FInputModeGameOnly InputMode;
			Controller->SetInputMode(InputMode);
			Controller->SetPause(false);
		} else {
			const FInputModeGameAndUI InputMode;
			Controller->SetInputMode(InputMode);
			Controller->SetPause(true);
		}

		Controller->bShowMouseCursor = !GameOnly;
	}
}
