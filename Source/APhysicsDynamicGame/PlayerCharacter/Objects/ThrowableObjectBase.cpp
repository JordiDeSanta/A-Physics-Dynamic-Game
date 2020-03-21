// Fill out your copyright notice in the Description page of Project Settings.


#include "ThrowableObjectBase.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AThrowableObjectBase::AThrowableObjectBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<UBoxComponent>("Collision");

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	ProjectileMovement->InitialSpeed = 300.f;
	ProjectileMovement->MaxSpeed = 500.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
}

// Called when the game starts or when spawned
void AThrowableObjectBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AThrowableObjectBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}