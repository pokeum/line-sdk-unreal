using System.IO;
using UnrealBuildTool;

public class IosPListUpdater : ModuleRules
{
	public IosPListUpdater(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PrivateDependencyModuleNames.AddRange(new string[] { "Core" });

		if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			AdditionalPropertiesForReceipt.Add("IOSPlugin",
				Path.Combine(
					Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath),
					"UPL.xml"
				)
			);
		}
	}
}