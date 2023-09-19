// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PixelProwlGameModeBase.generated.h"

class APlayerCharacter;
class UPixelProwlGameInstance;
/**
 * 
 */
UCLASS()
class PIXELPROWL_API APixelProwlGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	UPixelProwlGameInstance* GameInstance;

	UPROPERTY(BlueprintReadOnly)
	APlayerCharacter* PlayerCharacter;

	UPROPERTY(BlueprintReadOnly)
	APlayerController* PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UUserWidget> DefaultPlayPauseWidget;
	UPROPERTY()
	UUserWidget* PlayPauseWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UUserWidget> DefaultHUDWidget;
	UPROPERTY()
	UUserWidget* HUDWidget;
};
