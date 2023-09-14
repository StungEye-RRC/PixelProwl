// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PixelProwl/DataAssets/PickUpBehaviour.h"
#include "PickUp.generated.h"

class UPickUpDataAsset;
class UNiagaraComponent;
class UNiagaraSystem;
class UBoxComponent;

UCLASS()
class PIXELPROWL_API APickUp : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Init(UPickUpDataAsset* PickUpDataAsset);

private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Setup")
	UNiagaraComponent* PickupFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Setup")
	UBoxComponent* CollisionBox;

	UPROPERTY()
	TArray<UPickUpBehaviour*> Behaviours;

	UPROPERTY()
	UPickUpDataAsset* Data;
	
};
