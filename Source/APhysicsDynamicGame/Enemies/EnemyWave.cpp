// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyWave.h"

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
	for (int i = 0; i >= Enemies.Num(); i++)
	{
		GetWorld()->SpawnActor(
			Enemies[0]
		)
	}
}

