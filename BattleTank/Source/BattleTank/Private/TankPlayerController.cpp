// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)																						// If a tank is possessed by the Player Controller
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)																// Ticks the Player Controller (primer for ray-casting)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();																						//AimTowardsCrosshair();
	UE_LOG(LogTemp, Warning, TEXT("Player controller ticking:"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	// Get World Location through crosshair (line-trace)
	// If hits something
		//Tell controlled tank to aim at this point
}

