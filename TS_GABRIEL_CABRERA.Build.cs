// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TS_GABRIEL_CABRERA : ModuleRules
{
	public TS_GABRIEL_CABRERA(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
