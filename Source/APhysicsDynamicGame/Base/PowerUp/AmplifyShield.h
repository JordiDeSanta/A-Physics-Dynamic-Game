// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AmplifyShield.generated.h"

UCLASS()
class APHYSICSDYNAMICGAME_API AAmplifyShield : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmplifyShield();

	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(EditAnywhere, Category = "Collision", meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent* Capsule = nullptr;

	UPROPERTY(EditAnywhere, Category = "Movement")
		class URotatingMovementComponent* Rotation = nullptr;

	UPROPERTY(EditAnywhere, Category = "Restore")
		float RestoreQuantity = 100.f;
};
