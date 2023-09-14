// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpSpawner.h"
#include "PickUp.h"
#include "PixelProwl/DataAssets/PickUpDataAsset.h"
#include "Logging/StructuredLog.h"


// Sets default values
APickUpSpawner::APickUpSpawner() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void APickUpSpawner::BeginPlay() {
	Super::BeginPlay();
	if (!SpawnArea) {
		UE_LOGFMT(LogTemp, Error, "No spawner volume specified for the pick up spawner!");
		return;
	}
	
	if (!PickUpTypes.IsEmpty()) {
		APickUp* PickUp = GetWorld()->SpawnActorDeferred<APickUp>(APickUp::StaticClass(), this->GetActorTransform());
		PickUp->Init(PickUpTypes[0]);
		PickUp->FinishSpawning(this->GetActorTransform());
	}
}

void APickUpSpawner::SpawnPickups() {
	
}
