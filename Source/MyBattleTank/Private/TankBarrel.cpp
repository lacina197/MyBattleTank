// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
    // Move the barrel the right amount this frame
	// Given a max eleveation speed and the frame rate
    UE_LOG(LogTemp, Warning, TEXT("degreePerSecond: %f"), DegreesPerSecond);
}

