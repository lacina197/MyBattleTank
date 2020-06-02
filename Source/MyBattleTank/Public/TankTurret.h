// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS( meta=(BlueprintSpawnableComponent), hidecategories = ("Collision")) 
class MYBATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max downward speed, and +1 is max up movement
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 25;
	
};


/**
 * 
 1. Yeni bir class oluşturduk. 
 2. UCLASS için düzenleme yap ki blueprintten ulaşabilesin. --> Custom Component içinde TankTurret bulabilmen ve onu normal staticMesh ile değiştirebilmek için.
 3. Tank'in child i olacak şekilde yerleştir.
 4. Tank.h ve .cpp dosyalarında değişiklikler yap. --> Reference fonksiyonu tanımla ve blueprint için ayarlanabilir olsun.
 5. TankAimingComponent.h ve .cpp için de aynılarını yap.

 */