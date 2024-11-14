// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerFollower.generated.h"

class ACharacter;

UCLASS()
class PIXELPROWL_API APlayerFollower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerFollower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Mesh")
	UStaticMeshComponent* StaticMeshComponent;
   
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Follow")
	ACharacter* TargetCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Follow")
	float FollowDistance{500};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Follow")
	float FollowSpeed{500};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Follow")
	float RotationSpeed{4};
};
