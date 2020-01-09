// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "Components/PrimitiveComponent.h"
#include "WallRunComponent.generated.h"

/**
 * Detect walls and attach the movement to realize wallrun
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class APHYSICSDYNAMICGAME_API UWallRunComponent : public UCapsuleComponent
{
	GENERATED_BODY()

		UWallRunComponent();

public:
	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare overlap end function
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	bool bOnWall = false;

	class UCharacterMovementComponent* CharacterMovement;

};
