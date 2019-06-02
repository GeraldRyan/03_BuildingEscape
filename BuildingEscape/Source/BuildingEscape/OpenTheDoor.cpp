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
	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is missing Pressure Plate"),*GetOwner()->GetName());
	}

	
}

// Called every frame
void UOpenTheDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume 

	if(GetTotalMassOfActorsOnPlate() > TriggerMass) 
	{ 
		OnOpen.Broadcast();
	}
	else 
	{ 
		OnClose.Broadcast(); 
	}
}

float UOpenTheDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;

	// find all overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	// iterate through them adding their masses
	FString JoinedStr;
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass;
}
