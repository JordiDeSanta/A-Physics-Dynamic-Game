// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CalculateEnemyDistance.generated.h"

/**
 * 
 */
UCLASS()
class APHYSICSDYNAMICGAME_API UCalculateEnemyDistance : public UBTService
{
	GENERATED_BODY()

public:

	void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);

    UPROPERTY(EditDefaultsOnly, Category = "Blackboard")
        struct FBlackboardKeySelector EnemyKey;

    UPROPERTY(EditDefaultsOnly, Category = "Blackboard")
        struct FBlackboardKeySelector DistanceKey;
};
