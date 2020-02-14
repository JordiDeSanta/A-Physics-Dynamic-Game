// Fill out your copyright notice in the Description page of Project Settings.

#include "Base.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Math/UnrealMathUtility.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABase::ABase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ABase::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(RestoreShieldTimer, this, &ABase::RestoreShield, 1.f, true);
}

// Called every frame
void ABase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Health: %f"), BaseShield);
}

float ABase::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	if (bEmptyShield)
	{
		BaseHealth -= DamageAmount;	// Subtract health if the shield is empty.
	}
	else
	{
		BaseShield -= DamageAmount;	// Subtract shield if isn't empty.
	};

	if (BaseShield <= 0)
	{
		bEmptyShield = true; // Setting empty if the value is <= 0.
	};

	return BaseHealth + BaseShield;
}

void ABase::RestoreShield()
{
	if (bEmptyShield) { return; };
	BaseShield = FMath::Clamp(BaseShield + RestoreQuantityPerSecond, 0.f, MaxShield);
}


