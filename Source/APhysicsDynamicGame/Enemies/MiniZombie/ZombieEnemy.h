// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ZombieEnemy.generated.h"

UCLASS()
class APHYSICSDYNAMICGAME_API AZombieEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombieEnemy();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
		float Health = 50.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void SelfDestruct();

	UPROPERTY(EditDefaultsOnly, Category = "Explosion")
		class UParticleSystem* ExplosionVisualFX = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Explosion")
		class USoundBase* ExplosionSoundFX = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Explosion")
		float Damage = 40.f;
};
