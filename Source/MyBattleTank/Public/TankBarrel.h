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
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category=Setupp )
	float  MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category=Setupp )
	float  MaxElevationDegrees = 35;

	UPROPERTY(EditAnywhere, Category=Setupp )
	float  MinElevationDegrees = 0;



	
};
