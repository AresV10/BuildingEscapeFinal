// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	UPROPERTY(BlueprintAssignable)
	FOnOpenRequest OnOpenRequest;

	UPROPERTY(BlueprintAssignable)
	FOnOpenRequest OnCloseRequest;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void TeleportActor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	int OpenAngle = 0 ;
	int DoorCloseDelay = 0;

	AActor* Owner;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	//UPROPERTY(EditAnywhere)
	float GetTotalMassOfActorsOnTriggerPlate();

	UPROPERTY(EditAnywhere)
	float TriggerMass = 80.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate2;

	UPROPERTY(EditAnywhere)
	AActor* ActorTeleporting;
}; 
