// Fill out your copyright notice in the Description page of Project Settings.


#include "HoverComponent.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Character.h"
#include "Components/PrimitiveComponent.h"

#define OUT

// Sets default values for this component's properties
UHoverComponent::UHoverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHoverComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FHitResult HitResult;

	// Draw line to hover.
	bool bHoverLine = GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		GetComponentLocation(),
		GetUpVector() * HoverDistance,
		ECC_Visibility
	);

	if (bHoverLine)
	{
		UE_LOG(LogTemp, Warning, TEXT("WUHUU!"));
		HoverDelta = HoverDistance - HitResult.Distance; // Distance with the floor compared with expected dist.

		// Calculating params to hover.
		float Spring = HoverDelta * SpringCoefficient;
		float Damper = ((HoverDelta - PreviousHoverDelta) / GetWorld()->GetDeltaSeconds()) * DampingCoefficient;
			// Hover
		float Hover = Spring + Damper;

		// Castings to get a primitive comp.
		auto Player = Cast<class AActor>(GetOwner());
		auto PlayerRoot = Cast<class UPrimitiveComponent>(Player->GetRootComponent());
		
		// Force calculated by dist with the floor.
		FVector Force = GetUpVector() * Hover;
			// Applying force in root component of owner.
		PlayerRoot->AddForceAtLocation(Force, GetComponentLocation());
		// Setting for next iteration.
		PreviousHoverDelta = HoverDelta;
	}
}

