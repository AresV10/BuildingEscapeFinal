// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT(" Grabber is working"));
	// ...
	
}


 // Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	 //UE_LOG(LogTemp, Warning, TEXT("Position: %s, View: %s"), *(PlayerViewPointLocation).ToString(), *(PlayerViewPointRotation).ToString())

	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		PlayerViewPointLocation+(0.f,0.f,50.0f),
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		5.f
		);

}

