// Fill out your copyright notice in the Description page of Project Settings.


#include "ExampleSpawner.h"
#include "Components/InstancedStaticMeshComponent.h"

// Sets default values
AExampleSpawner::AExampleSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InstancedMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedMesh"));
	RootComponent = InstancedMesh;
}

// Called when the game starts or when spawned
void AExampleSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	if (!InstancedMesh) return;

	// Get the location of this spawner actor:
	FVector SpawnCenter{ GetActorLocation() };

	// Loop to NumberOfInstances times spawning an instanced static mesh each time:
	for (int i = 0; i < NumberOfInstances; i++)
	{
		// Arranging the instances in a circle:
		float Angle{ i * (2 * PI / NumberOfInstances) };
		float X{ CircleRadius * FMath::Cos(Angle) };
		float Y{ CircleRadius * FMath::Sin(Angle) };

		FVector SpawnPoint{ SpawnCenter + FVector(X, Y, 0) };
		FTransform InstanceTransform{ FQuat::Identity, SpawnPoint, FVector(1.0f) };
		
		// Spawn instanced meshes in a circle around this spawner actor.
		// Note: Second argument means that transforms location will be in world space!
		InstancedMesh->AddInstance(InstanceTransform, true);
	}
}

// Called every frame
void AExampleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (int i = 0; i < NumberOfInstances; i++)
	{
		FTransform InstanceTransform;
		// Get the i-th instance's transform in world space as an out param:
		InstancedMesh->GetInstanceTransform(i, InstanceTransform, true);

		// Get the location from the transform:
		FVector NewLocation{ InstanceTransform.GetLocation() };
		
		// Use sin to offset the Z of the location over time:
		float SineOffset{ GetGameTimeSinceCreation() + i * 2 * PI / NumberOfInstances };
		NewLocation.Z = GetActorLocation().Z + WaveHeight * FMath::Sin(SineOffset);
		
		// Set the transform with the updated location:
		InstanceTransform.SetLocation(NewLocation);

		// Update the i-th instance's transform in world space,
		// making sure to mark the render state as dirty (final param).
		InstancedMesh->UpdateInstanceTransform(i, InstanceTransform, true, true);
	}
}

