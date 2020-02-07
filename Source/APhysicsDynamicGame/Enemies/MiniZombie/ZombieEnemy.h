// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseEnemy.h"
#include "ZombieEnemy.generated.h"

UCLASS()
class APHYSICSDYNAMICGAME_API AZombieEnemy : public ABaseEnemy
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombieEnemy();

	virtual void Death(bool bKilled) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Explosion")
		class UParticleSystem* ExplosionVisualFX = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Explosion")
		class USoundBase* ExplosionSoundFX = nullptr;
};
