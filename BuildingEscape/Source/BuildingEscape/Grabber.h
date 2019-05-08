// Copyright Gerald Ryan 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	// This is a UInputComponent type eponymously named, pointed to nothing, but it will be referenced later, in the implementation file. 
	// It is still not perfectly clear to me why there is a need for a header file and an implementation file. 
	// It is a variable still but it is a pointer variable, right? Pointers are still variables, just not copies? They look the same on the surface
	// But behave differently underneath? But I came here to see what type it was, and what else was declared with it. We are going to use this variable
	// to run methods, so I should know something about this type, I think.
	// I don't see how BindAction method is linked to this class or type. 
	// BindAction is a functino of uinputcomponent but I only see that fact when I'm in hte UIC docs not the bindaction docs.	 f



	UInputComponent* InputComponent = nullptr;

	// Ray Cast and Grab what's in reach
	void Grab();

	// Called when grab is released
	void Release();


	
};
