// Copyright Gerald Ryan 2019

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenTheDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenTheDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenTheDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenTheDoor();
	void CloseDoor();



public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



private: 
	UPROPERTY(EditAnywhere)
	float OpenAngle = 85.0f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.0f;

	float LastDoorOpenTime;
	
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	AActor* ActorThatOpens;

	// Returns total mass in kg
	float GetTotalMassOfActorsOnPlate();
	AActor* Owner;
};
