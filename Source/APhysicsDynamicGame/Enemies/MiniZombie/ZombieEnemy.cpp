// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieEnemy.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Sound/SoundBase.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter/PlayerCharacter.h"

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

void AZombieEnemy::SelfDestruct(bool bKilled)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionVisualFX, GetActorTransform());
	UGameplayStatics::PlaySoundAtLocation(this, ExplosionSoundFX, GetActorLocation());

	auto PlayerCharacter = Cast<class APlayerCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!bKilled)
	{// Applying damage to enemy.
		UGameplayStatics::ApplyDamage(PlayerCharacter, Damage, GetController(), this, nullptr);
	};

	Destroy();
};

float AZombieEnemy::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	if (Health <= 0.f)
	{
		SelfDestruct(true);
	};

	Health -= DamageAmount;
	return DamageAmount;
};

