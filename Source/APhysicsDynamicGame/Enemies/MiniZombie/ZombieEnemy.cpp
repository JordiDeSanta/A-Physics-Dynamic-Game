// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieEnemy.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Sound/SoundBase.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter/PlayerCharacter.h"
#include "Base/Base.h"

// Sets default values
AZombieEnemy::AZombieEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Adjusting capsule settings.
	GetCapsuleComponent()->SetCapsuleSize(34.f, 44.f);
	Health = 40.f;
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

void AZombieEnemy::Death(bool bKilled, bool bBase)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionVisualFX, GetActorTransform());
	UGameplayStatics::PlaySoundAtLocation(this, ExplosionSoundFX, GetActorLocation());

	auto PlayerCharacter = Cast<class APlayerCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!bKilled)
	{// Applying damage to enemy.
		UGameplayStatics::ApplyDamage(PlayerCharacter, Damage, GetController(), this, nullptr);
	};

	auto PlayerBase = PlayerCharacter->PlayerBase;

	if (bBase)
	{// Applying damage to base.
		UGameplayStatics::ApplyDamage(PlayerBase, Damage, GetController(), this, nullptr);
	};

	Destroy();
};



