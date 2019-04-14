// Copyright Gerald Ryan 2019

#include "Grabber.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Engine/World.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"

#define OUT


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
	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get player viewpoint this tick
	FVector PlayerViewpointLocation;
	FRotator PlayerViewpointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
	OUT PlayerViewpointLocation, 
	OUT PlayerViewpointRotation
	);
	//UE_LOG(LogTemp, Warning, TEXT("The location is %s and the rotation is %s"), *PlayerViewpointLocation.ToString(), *PlayerViewpointRotation.ToString())

	FVector LineTraceEnd = PlayerViewpointLocation + PlayerViewpointRotation.Vector() * Reach;

	// Draw a red trace in world to visualize
	DrawDebugLine(
		GetWorld(),
		PlayerViewpointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		5.f
	);

	//Ray-cast out to reach distance

	// see what we hit


}

