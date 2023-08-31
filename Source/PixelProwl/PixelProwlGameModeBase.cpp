// Copyright Epic Games, Inc. All Rights Reserved.


#include "PixelProwlGameModeBase.h"

#include "Logging/StructuredLog.h"

void APixelProwlGameModeBase::BeginPlay()
{
	Super::BeginPlay(); 
	UE_LOGFMT(LogTemp, Warning, "Hello from C++ from Game Mode.");
}
