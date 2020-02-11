// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "HoverComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APHYSICSDYNAMICGAME_API UHoverComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHoverComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category = "Hover")
		float HoverDistance = 2000.f;

	UPROPERTY(EditAnywhere, Category = "Hover")
		float SpringCoefficient = 400.f;

	UPROPERTY(EditAnywhere, Category = "Hover")
		float DampingCoefficient = 80.f;

	UPROPERTY(EditAnywhere, Category = "Hover")
		float HoverDelta;

	UPROPERTY(EditAnywhere, Category = "Hover")
		float PreviousHoverDelta;
};
