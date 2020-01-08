// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "APhysicsDynamicGameGameMode.h"
#include "APhysicsDynamicGameHUD.h"
#include "APhysicsDynamicGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAPhysicsDynamicGameGameMode::AAPhysicsDynamicGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AAPhysicsDynamicGameHUD::StaticClass();
}
