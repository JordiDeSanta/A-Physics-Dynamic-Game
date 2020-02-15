// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyWave.h"
#include "Engine/World.h"
#include "BaseEnemy.h"

// Sets default values
AEnemyWave::AEnemyWave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyWave::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnEnemies();
}

// Called every frame
void AEnemyWave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyWave::SpawnEnemies()
{
	for (auto& Enemy : EnemiesMap)
	{
		for (int32 i = 0; i < Enemy.Key; i++)
		{
			FVector RandomPoint = FMath::RandPointInBox(SpawnBox);

			auto Spawned = GetWorld()->SpawnActor<ABaseEnemy>(
				Enemy.Value
			);

			Spawned->SetActorRelativeLocation(RandomPoint);
			Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
		};
	}
}

