// Fill out your copyright notice in the Description page of Project Settings.


#include "WallRunComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UWallRunComponent::UWallRunComponent()
{
	InitCapsuleSize(60.f, 100.f);
	SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SetGenerateOverlapEvents(true);
	SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	bEditableWhenInherited = true;
	SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	SetNotifyRigidBodyCollision(true);

	OnComponentBeginOverlap.AddDynamic(this, &UWallRunComponent::OnOverlapBegin);
	OnComponentEndOverlap.AddDynamic(this, &UWallRunComponent::OnOverlapEnd);
}

void UWallRunComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if ((OtherActor != nullptr) && (OtherActor != GetOwner()) && (OtherComp != nullptr))
	{
		auto PlayerCharacter = GetWorld()->GetFirstPlayerController()->GetCharacter();
		auto PlayerCharacterCasted = Cast<APlayerCharacter>(PlayerCharacter);
		auto PlayerCamera = PlayerCharacterCasted->GetCamera();
		FVector PlayerDirection = PlayerCamera->GetForwardVector();

		bool bWallActor = OtherActor->ActorHasTag("Wall");

		CharacterMovement = PlayerCharacter->GetCharacterMovement();

		if (bWallActor && CharacterMovement->IsFalling())
		{
			bOnWall = true;
			UE_LOG(LogTemp, Warning, TEXT("ISFALLING YEAH!!!!"));
			FVector PlayerDirection = PlayerCamera->GetForwardVector();

			auto PlayerController = GetWorld()->GetFirstPlayerController();
			float TimePressed = PlayerController->GetInputKeyTimeDown(FKey("SpaceBar"));
			bool bPressed = TimePressed > 0;

			if (bPressed)
			{
				UE_LOG(LogTemp, Warning, TEXT("SPACEBAR PRESSED!!!!"));
				if (bOnWall)
				{
					CharacterMovement->GravityScale = 0.f;
					CharacterMovement->SetPlaneConstraintNormal(FVector(0, 0, 1));
					CharacterMovement->AddForce(PlayerDirection * 20000.f);
					UE_LOG(LogTemp, Warning, TEXT("WUHU WALLRUN!!!!"));
				}
				else
				{
					CharacterMovement->GravityScale = 1.f;
					UE_LOG(LogTemp, Warning, TEXT("WUHU NO WALLRUN :("));
				};
			}
			else
			{
				CharacterMovement->GravityScale = 1.f;
				UE_LOG(LogTemp, Warning, TEXT("SPACEBAR UNPRESSED!!!!"));
			};
		};
	};
}

void UWallRunComponent::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	
	if ((OtherActor != nullptr) && (OtherActor != GetOwner()) && (OtherComp != nullptr))
	{
		bool bWallActor = OtherActor->ActorHasTag("Wall");
		if (bWallActor)
		{
			CharacterMovement->GravityScale = 1.f;
			CharacterMovement->SetPlaneConstraintNormal(FVector(0, 0, 0));
			bOnWall = false;
			UE_LOG(LogTemp, Warning, TEXT("WUHU END WALLRUN!!!!"));
		}
	};
}
