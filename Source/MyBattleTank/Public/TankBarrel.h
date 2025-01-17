// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta=(BlueprintSpawnableComponent), hidecategories = ("Collision")) //TankAimingComponent'tan aldık. 
class MYBATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max downward speed, and +1 is max up movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category=Setupp )
	float  MaxDegreesPerSecond = 10;

	UPROPERTY(EditAnywhere, Category=Setupp )
	float  MaxElevationDegrees = 30;

	UPROPERTY(EditAnywhere, Category=Setupp )
	float  MinElevationDegrees = 0;

};

