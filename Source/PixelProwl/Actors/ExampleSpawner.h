// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExampleSpawner.generated.h"

class UInstancedStaticMeshComponent;

UCLASS()
class PIXELPROWL_API AExampleSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExampleSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
	UInstancedStaticMeshComponent* InstancedMesh;

	UPROPERTY(EditAnywhere)
	float NumberOfInstances{10};
	
	UPROPERTY(EditAnywhere)
	float CircleRadius{500};
	
	UPROPERTY(EditAnywhere)
	float WaveHeight{200};
};
