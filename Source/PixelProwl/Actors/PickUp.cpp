// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp.h"
#include "../DataAssets/PickUpDataAsset.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/BoxComponent.h"
#include "Logging/StructuredLog.h"


// Sets default values
APickUp::APickUp()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(FName("Collision Box"));
	SetRootComponent(CollisionBox);
}

// Called when the game starts or when spawned
void APickUp::BeginPlay() {
	Super::BeginPlay();
	
	UE_LOGFMT(LogTemp, Warning, "Pick Up Spawned: {0} Points: {1}", Data->DisplayName.ToString(), Data->Points);
	if (CollisionBox) {
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APickUp::OnBeginOverlap);
	}
	
	if (Data) {
		PickupFX = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Data->Particles, GetActorTransform().GetLocation());
	} else {
		UE_LOGFMT(LogTemp, Error, "No data asset specified for pick-up.");
	}
}
	

// Called every frame
void APickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/*
 * TODO: Refactor such that we only keep the pointer to the data asset.
 * This way we can pass the pass both the data asset and the player character
 * to the Behaviour method!
 */
void APickUp::Init(UPickUpDataAsset* PickUpDataAsset) {
	Data = PickUpDataAsset;
	for (TSubclassOf<UPickUpBehaviour> Behaviour : Data->Behaviours) {
		Behaviours.Emplace(NewObject<UPickUpBehaviour>(this, Behaviour));
	}
}

void APickUp::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	UE_LOGFMT(LogTemp, Warning, "Pick Up Overlapped!");
	if (OtherActor && OtherActor->IsA(APlayerCharacter::StaticClass())) {
		
		UE_LOGFMT(LogTemp, Warning, "Pick Up Overlapped with Player!");
		if (!Behaviours.IsEmpty()) {
			for (UPickUpBehaviour* Behaviour : Behaviours) {
				Behaviour->Behaviour(Cast<APlayerCharacter>(OtherActor), Data);
			}
		}
		PickupFX->DestroyInstance();
		Destroy();
	}
}

