// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SelfDestruction.generated.h"

/**
 * 
 */
UCLASS()
class APHYSICSDYNAMICGAME_API USelfDestruction : public UBTTaskNode
{
	GENERATED_BODY()

		EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
