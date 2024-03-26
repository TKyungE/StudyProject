// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class StudyProject : ModuleRules
{
	public StudyProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core", "CoreUObject", "Engine", "InputCore",
			
			"Json", "JsonUtilities",
            "EnhancedInput",

            "NavigationSystem",
			"AIModule",
            "GameplayTasks",
        });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
