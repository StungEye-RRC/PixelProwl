// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayPauseMenu.generated.h"

class UPixelProwlGameInstance;
class UTextBlock;
class UButton;

/**
 * See BindWidget comment in PlayerHUD.h.
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
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* FinalScore;

	UPROPERTY(BlueprintReadOnly)
	UPixelProwlGameInstance* GameInstance;
	
	UPROPERTY(BlueprintReadOnly)
	bool GameIsPaused = true;

	UPROPERTY(BlueprintReadOnly)
	bool GameIsOver = false;
	
private:
	UFUNCTION()
	void OnQuit();

	UFUNCTION()
	void OnTimerEnd(int32 Score);
};
