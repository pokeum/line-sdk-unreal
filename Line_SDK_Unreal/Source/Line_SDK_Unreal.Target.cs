// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

// ReSharper disable once InconsistentNaming
public class Line_SDK_UnrealTarget : TargetRules
{
	public Line_SDK_UnrealTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Line_SDK_Unreal" } );
		
		if (Target.Platform == UnrealTargetPlatform.Mac ||
		    Target.Platform == UnrealTargetPlatform.IOS)
		{
			bOverrideBuildEnvironment = true;

			string additionalCompilerArguments =
				" -Wno-bitwise-instead-of-logical" +
				" -Wno-unused-but-set-variable" +
				" -Wno-deprecated-builtins" +
				" -Wno-bitfield-constant-conversion" +
				" -Wno-unknown-warning-option";

			if (Target.Platform == UnrealTargetPlatform.IOS)
			{
				additionalCompilerArguments +=
					" -Wno-objc-property-no-attribute" +
					" -Wno-nullability-completeness" +
					" -Wno-invalid-unevaluated-string";
			}

			AdditionalCompilerArguments = additionalCompilerArguments;
		}
	}
}
