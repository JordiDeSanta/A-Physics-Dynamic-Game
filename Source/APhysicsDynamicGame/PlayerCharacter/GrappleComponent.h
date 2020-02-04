// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GrappleComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShootGrapple);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FResetGrapple);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APHYSICSDYNAMICGAME_API UGrappleComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrappleComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GrappleGun")
	TSubclassOf<class ALaserProjectile> LaserProjectileBlueprint = nullptr;

	/// Events
	UPROPERTY(BlueprintAssignable)
		FShootGrapple ShootGrappleEvent;

	UPROPERTY(BlueprintAssignable)
		FResetGrapple ResetGrappleEvent;

	FTimerHandle GrappleTimer;

	UFUNCTION()
		void ShootLaser();

	UFUNCTION()
		void OnTimerEnd();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GrappleGun")
		float GrappleVelocityMultiplier = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GrappleGun")
		float Reach = 10000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GrappleGun")
		bool bCanShoot = true;

	/** Shoots and resets grapple cable and add impulse to character*/
	UFUNCTION()
	void ShootGrapple();

	UPROPERTY(BlueprintReadOnly, Category = "GrappleGun")
		FVector HookPos;
};
