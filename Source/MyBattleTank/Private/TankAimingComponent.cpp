// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // TODO should this really tick?

	// ...
}


void UTankAimingComponent::setBarrelReference(UTankBarrel* BarrelToSet)
{
	if(!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::setTurretReference(UTankTurret* TurretToSet)
{
	if(!TurretToSet) { return; }
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if( !Barrel ) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
		(
			this,
			OutLaunchVelocity,
			StartLocation,
			HitLocation,
			LaunchSpeed,
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace // bug line
		);
	
	if ( bHaveAimSolution )
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim Solution found."), Time);
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: NO Aim Solve found."), Time);
	}
	
	// If no solution found do nothing
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Work-out difference bw current barrel rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	// Move the barrel the right amount this frame
	// Given a max eleveation speed and the frame rate
	Barrel->Elevate(DeltaRotator.Pitch); // TODO remove magic number

}


