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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float BaseHealth = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float BaseShield = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float RestoreQuantityPerSecond = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float MaxShield = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float MaxHealth = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		bool bEmptyShield = false;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		class UStaticMeshComponent* Mesh;

};
