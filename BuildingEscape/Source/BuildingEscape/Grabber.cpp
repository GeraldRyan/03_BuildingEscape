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

	/// Draw a red trace in world to visualize
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

	// set up query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	// Line Trace (Ray-cast) out to reach distance
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewpointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);


	// see what we hit

	AActor* HitName = Hit.GetActor();
	if (HitName)
	{
		UE_LOG(LogTemp, Warning, TEXT("The name of the hit object is %s"), *HitName->GetName())
	}
	// Get an Actor* from Hit (why is this a pointer? The ray hits an object as specified in the arguments above. That is stored somewhere. I think it is stored as Hit. Hit is the 'object' that is returned from the code function above. FHitresult is a data type or class from unreal's code that we store the hit as, under the name hit. Ok. We ran a method from the getworld function, we ran a method in that. It is interesting that it would have been located there but it was. I guess we do top down. I should look at the documentation about getworld. There is so much documentation in the world (of computing). This is good. IT stretches me. It is a pointer so it is accessed by ->. That makes it a pointer, huh. Is all the getworld's a -> or is all the linetracesingle a pointer. This is confusing. We point to getworld because it's a HUGE object, so we can't keep copying. We'd need to point to it of course. This will be standard. Ok so it's stored as hit. I don't know if hit is a pointer but getworld is a pointer- or the function returns a pointer. We can run that function in our header and our cpp file, our component. So the hit should return, so I have to reseaerch the FHitResult to see about that, but I imagine it will be something like Hit->getowner()->getname or something like that and then we'll store it as a variable, like NameofHitObject = Hit->getowner()... and then UE_LOG hit etc as the syntax requires. I could try this and test it and I can read to confirm. Not that I'm lazy but this taxes the mind more than it might be worth. Let's see. 

	//

}

