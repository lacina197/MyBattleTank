// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"




void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    //Protecting Pointer
    auto PlayerTank = GetPlayerTank();
    if(!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
    }
    else
    {
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if(!PlayerPawn) { return nullptr; } 
    // eğer bulamazsa null dönsün ki crash olmasın.
    return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (GetPlayerTank())
    {
        GetControlledTank()->AimAt( GetPlayerTank()->GetActorLocation() );
    }
    

}
