// Copyright Gerald Ryan 2019

#include "OpenTheDoor.h"
#include "Engine/World.h"
#include "Classes/Components/PrimitiveComponent.h"


#define OUT

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
	Owner = GetOwner();


	
}

void UOpenTheDoor::OpenTheDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}

void UOpenTheDoor::CloseDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}


// Called every frame
void UOpenTheDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume 

	if(GetTotalMassOfActorsOnPlate() > 30.f) // TODO make into a parameter
	{
	// If the ActorThatOpens is in the volume, then open door
		OpenTheDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	// Check if it's time to close the door
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) { CloseDoor(); }
}

float UOpenTheDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;

	// find all overlapping actors
	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	// iterate through them adding their masses
	FString JoinedStr;
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass;
}
