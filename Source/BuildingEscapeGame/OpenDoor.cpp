// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

ATriggerVolume* PressurePlate2;

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorTeleporting = GetWorld()->GetFirstPlayerController()->GetPawn();
	Owner = GetOwner();
}



// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetTotalMassOfActorsOnTriggerPlate()> TriggerMass)
	{
		OnOpenRequest.Broadcast();
	}
	else
	{
		OnCloseRequest.Broadcast();
	}
	
	if (PressurePlate2->IsOverlappingActor(ActorTeleporting))
	{
		TeleportActor();
	}
		
}

float UOpenDoor::GetTotalMassOfActorsOnTriggerPlate()
{
	float TotalMass = 0.f;
	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on Pressure Plate"), *Actor->GetName())
	}
	return TotalMass;
}

void UOpenDoor::TeleportActor()
{
	//ActorTeleporting = GetWorld()->GetFirstPlayerController()->GetPawn();
	ActorTeleporting ->SetActorLocation(FVector(1069.f, 113.f, 112.000687f));
	UE_LOG(LogTemp, Warning, TEXT("%s on Pressure Plate And IT WORKSSSSSS"), *ActorTeleporting->GetName())

}
