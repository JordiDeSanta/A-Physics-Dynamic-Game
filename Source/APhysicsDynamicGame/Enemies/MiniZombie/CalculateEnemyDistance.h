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

    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:

    UPROPERTY(EditAnywhere, Category = "Blackboard")
        struct FBlackboardKeySelector EnemyKey;

    UPROPERTY(EditAnywhere, Category = "Blackboard")
        struct FBlackboardKeySelector DistanceKey;
};
