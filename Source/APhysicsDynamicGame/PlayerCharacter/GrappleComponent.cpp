// Fill out your copyright notice in the Description page of Project Settings.


#include "GrappleComponent.h"
#include "PlayerCharacter.h"
#include "Engine/World.h"
#include "Camera/CameraComponent.h"
#include "TimerManager.h"

#define OUT

// Sets default values for this component's properties
UGrappleComponent::UGrappleComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrappleComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrappleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGrappleComponent::ShootGrapple()
{
	auto Owner = Cast<APlayerCharacter>(GetOwner());
	auto StartGrapple = Owner->GetActorLocation();
	auto MaxGrapple = Owner->GetCamera()->GetForwardVector() * Reach;
	FHitResult GrappleHitResult;

	GetWorld()->LineTraceSingleByChannel(
		GrappleHitResult OUT,
		StartGrapple,
		MaxGrapple,
		ECollisionChannel::ECC_Visibility
	);

	auto bGrappelled = GrappleHitResult.bBlockingHit;
	HookPos = GrappleHitResult.Location;

	ShootGrappleEvent.Broadcast();

	if (!bGrappelled) { ResetGrappleEvent.Broadcast(); return; };

	auto LaunchVelocity = (HookPos - StartGrapple) * GrappleVelocityMultiplier;

	bCanShoot = false;

	Owner->LaunchCharacter(LaunchVelocity, true, true);

	UE_LOG(LogTemp, Warning, TEXT("Launched"));

	GetWorld()->GetTimerManager().SetTimer(GrappleTimer, this, &UGrappleComponent::OnTimerEnd, 0.5, false);
};


void UGrappleComponent::OnTimerEnd()
{
	bCanShoot = true;
	ResetGrappleEvent.Broadcast();
};



