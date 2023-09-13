// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpSpawner.generated.h"

class APickUp;
class ALocationVolume;

UCLASS()
class PIXELPROWL_API APickUpSpawner : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickUpSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Spawner")
	ALocationVolume* SpawnArea;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawner")
	TArray<TSubclassOf<APickUp>> PickUpTypes;

	UFUNCTION(BlueprintCallable, Category = "Spawner")
	void SpawnPickups();
};
