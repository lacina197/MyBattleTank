// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
//Protecting Pointer
    auto ControlledTank = GetControlledTank();
    if(!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayController not possesing a tank"));
    }
    else
    {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimTowardsCrosshair();
    
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()) { return; }
    
    //get world location if linetrace through crosshair
    //if it hits the landscape
     //tell controlled tank to aim at this point

    FVector HitLocation; // Out Parameter

    if(GetSightRayHitLocation(HitLocation))
    {
        // TODO Tell controlled tank to aim at this point
        GetControlledTank()->AimAt(HitLocation);
    }

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
    // find the crosshair position
    int32 ViewPortSizeX, ViewPortSizeY;
    GetViewportSize(ViewPortSizeX, ViewPortSizeY);
    auto ScreenLocation = FVector2D(ViewPortSizeX * CrosshairXLocation, ViewPortSizeY * CrosshairYLocation );

    FVector LookDirection;
    
    // de-project the screen position of the crosshair to a world direction
    if (GetLookDirection(ScreenLocation, LookDirection))
    {
        // line-trace along that look direction, see what we hit up tp max range
        GetLookVectorHitLocation(LookDirection, HitLocation);
        
    }
    
    
    return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
    FVector CameraWorldLocation; // will be discarded
 
    return DeprojectScreenPositionToWorld(
    ScreenLocation.X, 
    ScreenLocation.Y, 
    CameraWorldLocation, 
    LookDirection
    );
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
    FHitResult HitResult;
    auto StartLocation = PlayerCameraManager->GetCameraLocation();
    auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
    if ( GetWorld()->LineTraceSingleByChannel(
                HitResult,
                StartLocation,
                EndLocation,
                ECollisionChannel::ECC_Visibility) 
        )
    {
        HitLocation = HitResult.Location;
        return true;
    }
    HitLocation = FVector(0); // hiçbir şeye çarpmazsa 0 dönsün.
    return false;

}


