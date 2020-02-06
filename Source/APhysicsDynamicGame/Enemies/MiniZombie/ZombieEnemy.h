// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Sound/SoundBase.h"
#include "Particles/ParticleSystemComponent.h"
#include "ZombieEnemy.generated.h"

class UParticleSystemComponent;
class USoundBase;

UCLASS()
class APHYSICSDYNAMICGAME_API AZombieEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombieEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Explosion")
		UParticleSystemComponent* ExplosionVisualFX = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Explosion")
		USoundBase* ExplosionSoundFX = nullptr;
};
