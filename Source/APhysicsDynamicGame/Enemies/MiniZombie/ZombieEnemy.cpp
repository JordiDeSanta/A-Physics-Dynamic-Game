// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieEnemy.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Sound/SoundBase.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AZombieEnemy::AZombieEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Adjusting capsule settings.
	GetCapsuleComponent()->SetCapsuleSize(34.f, 44.f);
}

// Called when the game starts or when spawned
void AZombieEnemy::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AZombieEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZombieEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AZombieEnemy::SelfDestruct()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionVisualFX, GetActorTransform());
	UGameplayStatics::PlaySoundAtLocation(this, ExplosionSoundFX, GetActorLocation());
	Destroy();
};

