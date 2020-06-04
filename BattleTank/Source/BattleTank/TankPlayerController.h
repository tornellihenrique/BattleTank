// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
    GENERATED_BODY()

private:
    UPROPERTY(EditDefaultsOnly)
    float CrossHairXLocation = 0.5f;

    UPROPERTY(EditDefaultsOnly)
    float CrossHairYLocation = 0.3333f;

    UPROPERTY(EditDefaultsOnly)
    float LineTraceRange = 1000000.f;

    void AimTowardsCrosshair();

    bool GetSightRayHitLocation(FVector &OutHitLocation) const;

    ATank *GetControlledTank() const;

    bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;

    bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;

public:
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;
};
