// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"	
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"										// Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
		
private:
	// Starts tank moving barrel so that the shot will hit where the crosshair intersects world
	void AimTowardsCrosshair();

	// Return OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;												// this will mutate (change) the FVector (OUT PARAMETER)

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	};
