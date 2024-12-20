using System.IO;
using UnrealBuildTool;

public class LineSDK : ModuleRules
{
	public LineSDK(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject", });
		PrivateDependencyModuleNames.AddRange(new string[] { "Settings", "Json" });

		string pluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);

		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });

			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(pluginPath, "LineSDK_Android_UPL.xml"));
		}
		else if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			AdditionalPropertiesForReceipt.Add("IOSPlugin", Path.Combine(pluginPath, "LineSDK_IOS_UPL.xml"));
		}
	}
}