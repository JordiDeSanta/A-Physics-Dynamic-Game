// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseEnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class APHYSICSDYNAMICGAME_API ABaseEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ABaseEnemyAIController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AIPerception")
	class UAIPerceptionComponent* AIPerception = nullptr;
};
