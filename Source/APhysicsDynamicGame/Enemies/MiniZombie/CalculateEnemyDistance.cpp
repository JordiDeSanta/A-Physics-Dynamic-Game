// Fill out your copyright notice in the Description page of Project Settings.


#include "CalculateEnemyDistance.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Actor.h"
#include "AIController.h"
#include "Math/Vector.h"

void UCalculateEnemyDistance::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	// Saving necessary components.
	auto AIOwner = OwnerComp.GetAIOwner();
	auto Blackboard = OwnerComp.GetBlackboardComponent();

	// Enemy params.
	auto EnemyActor = Cast<class AActor>(Blackboard->GetValueAsObject(EnemyKey.SelectedKeyName));
	auto EnemyPosition = EnemyActor->GetActorLocation();

	// Owner params.
	auto OwnerActor = AIOwner->GetPawn();
	auto OwnerPosition = OwnerActor->GetActorLocation();

	// Calculate distance.
	auto Distance = FVector::Distance(OwnerPosition, EnemyPosition);

	// Set distance in blackboard.
	Blackboard->SetValueAsFloat(DistanceKey.SelectedKeyName, Distance);
};