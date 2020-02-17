// Fill out your copyright notice in the Description page of Project Settings.

#include "AmplifyShield.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "PlayerCharacter/PlayerCharacter.h"
#include "Base/Base.h"

// Sets default values
AAmplifyShield::AAmplifyShield()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Init capsule.
	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	Capsule->SetGenerateOverlapEvents(true);
	Capsule->OnComponentBeginOverlap.AddDynamic(this, &AAmplifyShield::OnOverlapBegin);

	// Init static mesh.
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	// Init rotating movement.
	Rotation = CreateDefaultSubobject<URotatingMovementComponent>("Rotation");
	Rotation->RotationRate = FRotator(0.f, 90.f, 0.f);
}

// Called when the game starts or when spawned
void AAmplifyShield::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmplifyShield::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAmplifyShield::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Other Actor is the actor that triggered the event. Check that is not ourself.  
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		auto Player = Cast<class APlayerCharacter>(OtherActor);

		if (Player)
		{
			auto Base = Player->PlayerBase;
			Base->BaseShield += RestoreQuantity;
			Base->bEmptyShield = false;
			Destroy();
		};
	};
};



