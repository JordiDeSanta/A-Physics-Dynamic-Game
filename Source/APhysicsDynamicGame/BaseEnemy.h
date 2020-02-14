// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseEnemy.generated.h"

UCLASS()
class APHYSICSDYNAMICGAME_API ABaseEnemy : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseEnemy();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	virtual void Death(bool bKilled, bool bBase);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Health")
		float Health = 50.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Explosion")
		float Damage = 50.f;
};
