// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemyAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ABaseEnemyAIController::ABaseEnemyAIController()
{
	// AIPerception.
		// Creating Components.
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>("AIPerception");
};

