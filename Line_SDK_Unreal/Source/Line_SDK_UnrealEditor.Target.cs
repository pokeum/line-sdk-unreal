// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

// ReSharper disable once InconsistentNaming
public class Line_SDK_UnrealEditorTarget : TargetRules
{
	public Line_SDK_UnrealEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Line_SDK_Unreal" } );
		
		if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			bOverrideBuildEnvironment = true;
			AdditionalCompilerArguments = "-Wno-error";
		}
	}
}
