// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseEnemy.h"
#include "Drone.generated.h"

/**
 * 
 */
UCLASS()
class APHYSICSDYNAMICGAME_API ADrone : public ABaseEnemy
{
	GENERATED_BODY()
	
public:
	ADrone();

	void Death(bool bKilled) override;
};
