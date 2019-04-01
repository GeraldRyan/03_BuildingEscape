// Copyright Gerald Ryan 2019

#include "OpenTheDoor.h"
#include "Engine/World.h"
#include "Classes/Components/PrimitiveComponent.h"


// Sets default values for this component's properties
UOpenTheDoor::UOpenTheDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenTheDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

	
}

void UOpenTheDoor::OpenTheDoor()
{
	// Find the owning actor

	AActor* Owner = GetOwner();

	// Create a rotator

	FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f);

	// Set the door rotation

	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenTheDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume 

	if(PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
	// If the ActorThatOpens is in the volume, then open door
		OpenTheDoor();
	}
}

