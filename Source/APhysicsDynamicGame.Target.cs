// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class APhysicsDynamicGameTarget : TargetRules
{
	public APhysicsDynamicGameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("APhysicsDynamicGame");
	}
}
