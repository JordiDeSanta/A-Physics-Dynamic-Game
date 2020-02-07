// Fill out your copyright notice in the Description page of Project Settings.


#include "SelfDestruction.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemies/MiniZombie/ZombieEnemy.h"
#include "AIController.h"
#include "PlayerCharacter/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type USelfDestruction::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Getting controller pawn.
	auto AIOwner = OwnerComp.GetAIOwner();
	auto Zombie = Cast<class AZombieEnemy>(AIOwner->GetPawn());

	// Calling zombie to SD in case of.. (Decorator).
	Zombie->Death(false);

	return EBTNodeResult::Succeeded;
};
