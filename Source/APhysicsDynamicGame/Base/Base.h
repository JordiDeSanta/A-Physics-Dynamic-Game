// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base.generated.h"

UCLASS()
class APHYSICSDYNAMICGAME_API ABase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	void RestoreShield();

	FTimerHandle RestoreShieldTimer;

protected:
	UPROPERTY(EditAnywhere, Category = "Health")
		float BaseHealth = 1000.f;

	UPROPERTY(EditAnywhere, Category = "Health")
		float BaseShield = 500.f;

	UPROPERTY(EditAnywhere, Category = "Health")
		float RestoreQuantityPerSecond = 1.f;

private: 
	float MaxShield = 500.f;

	bool bEmptyShield = false;
};
