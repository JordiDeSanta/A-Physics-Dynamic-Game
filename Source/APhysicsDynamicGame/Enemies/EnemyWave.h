// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyWave.generated.h"

UCLASS()
class APHYSICSDYNAMICGAME_API AEnemyWave : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyWave();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnEnemies();

	UPROPERTY(EditAnywhere, Category = "Enemies")
		TMap<TSubclassOf<class ABaseEnemy>, int32> Enemies;
};
