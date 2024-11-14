// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFollower.h"

#include "EnvironmentQuery/Generators/EnvQueryGenerator_CurrentLocation.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APlayerFollower::APlayerFollower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMeshComponent;
}

// Called when the game starts or when spawned
void APlayerFollower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerFollower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const FVector CurrentLocation{ GetActorLocation() };
	const FVector TargetLocation{ TargetCharacter->GetActorLocation() };

	// Expensive OP for tick!
	const float Distance = FVector::Dist(TargetLocation, CurrentLocation);

	if (Distance > FollowDistance)
	{
		const FVector Direction{ (TargetLocation - CurrentLocation).GetSafeNormal() };
		const FVector Movement{ Direction * FollowSpeed * DeltaTime };
		const FVector NewLocation{ CurrentLocation + Movement };
		SetActorLocation(NewLocation);
	}
	
	const FRotator LookAtRotation{UKismetMathLibrary::FindLookAtRotation(CurrentLocation, TargetLocation)};
	const FRotator CurrentRotation{ GetActorRotation() };
	if (LookAtRotation != CurrentRotation)
	{
		SetActorRotation(FMath::RInterpTo(CurrentRotation, LookAtRotation, DeltaTime, RotationSpeed));
	}
}

