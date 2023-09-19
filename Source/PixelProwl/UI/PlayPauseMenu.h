// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayPauseMenu.generated.h"

class UPixelProwlGameInstance;
class UTextBlock;
class UButton;

/**
 * 
 */
UCLASS()
class PIXELPROWL_API UPlayPauseMenu : public UUserWidget {
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnPlayPause();
	
protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* PlayPauseButton;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* PlayPauseText;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* QuitButton;

	UPROPERTY(BlueprintReadOnly)
	UPixelProwlGameInstance* GameInstance;
	
	UPROPERTY(BlueprintReadOnly)
	bool GameIsPaused = true;
	
private:
	UFUNCTION()
	void OnQuit();
};
