// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.generated.h"

class UTextBlock;

/**
 * This UUserWidget base class makes use of the BindWidget meta UPROPERTY such that
 * the widgets can be controlled from C++ but defined and visually placed in Blueprint.
 * See: https://benui.ca/unreal/ui-bindwidget/
 */
UCLASS(Abstract)
class PIXELPROWL_API UPlayerHUD : public UUserWidget {
	GENERATED_BODY()

	virtual bool Initialize() override;

	UFUNCTION()
	void OnScoreChanged(int32 NewScore);

	UFUNCTION()
	void OnTimerChanged(FString NewTimer);
	
protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* Score;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* Timer;
};
