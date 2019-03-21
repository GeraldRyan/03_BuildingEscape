// Copyright Gerald Ryan 2019

#include "OpenDoor.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// Find the Owning Actor // I'm not sure what this means or why this is required? Is it just like actorID?

	AActor* Owner = GetOwner();

	// Create a Rotator

	FRotator NewRotation = FRotator(0.f,60.f,0.f);

	// Set the Door Rotation

	Owner->SetActorRotation(NewRotation);



}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

