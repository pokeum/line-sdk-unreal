// ReSharper disable InconsistentNaming

using System;
using System.IO;
using System.Text;
using UnrealBuildTool;

public class LineSDK : ModuleRules
{
	public LineSDK(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject", "Json" });
		PrivateDependencyModuleNames.AddRange(new string[] { "Settings" });

		// Read Line SDK Settings
		var Settings = new LineSDKSettings();
		ReadLineSDKSettings(ref Settings);
		Console.WriteLine(Settings.ToString());
		
		// Update Config.h
		UpdateConfig(Settings);
		
		string pluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);

		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });

			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(pluginPath, "LineSDK_Android_UPL.xml"));
		}
		else if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			AdditionalPropertiesForReceipt.Add("IOSPlugin", Path.Combine(pluginPath, "LineSDK_IOS_UPL.xml"));
			
#if UE_4_26_OR_LATER
			PublicAdditionalFrameworks.Add(
				new Framework(
					"LineSDKWrapper",
					"../ThirdParty/iOS/LineSDKWrapper.embeddedframework.zip",
					null,
					true
				)
			);
#else
			PublicAdditionalFrameworks.Add(
				new Framework(
					"LineSDKWrapper",
					"../ThirdParty/iOS/LineSDKWrapper.embeddedframework.zip"
				)
			);
#endif
		}
	}

	
#region Line SDK Settings
	
	class LineSDKSettings
	{
		public string ChannelID;
		public string UniversalLinkURL;

		public override string ToString()
		{
			return new StringBuilder()
				.Append("Line SDK Settings:\n")
				.AppendFormat("\tChannelID: \"{0}\"\n", ChannelID)
				.AppendFormat("\tUniversalLinkURL: \"{0}\"\n", UniversalLinkURL)
				.ToString();
		}
	}

	private void ReadLineSDKSettings(ref LineSDKSettings Settings)
	{
		var Ini = ConfigCache.ReadHierarchy(ConfigHierarchyType.Engine, Target.ProjectFile.Directory, Target.Platform);
		const string SettingsSection = "/Script/LineSDK.LineSDKSettings";
		Ini.GetString(SettingsSection, "ChannelID", out Settings.ChannelID);
		Ini.GetString(SettingsSection, "UniversalLinkURL", out Settings.UniversalLinkURL);
	}

	private void UpdateConfig(LineSDKSettings Settings)
	{
		var ConfigPath = Path.Combine(ModuleDirectory, "Private/LineSDKConfig.h");
		try
		{
			if (!File.Exists(ConfigPath))
			{
				File.Create(ConfigPath).Dispose();
				Console.WriteLine("Create file : {0}", ConfigPath);
			}

			var Content = new StringBuilder()
				.Append("#pragma once\n\n")
				.Append("namespace LineSDKConfig\n")
				.Append("{\n")
				.AppendFormat("\tconst FString& ChannelID = \"{0}\";\n", Settings.ChannelID)
				.AppendFormat("\tconst FString& UniversalLinkURL = \"{0}\";\n", Settings.UniversalLinkURL)
				.Append("}")
				.ToString();

			// Overwrite the updated content
			File.WriteAllText(ConfigPath, Content);
			Console.WriteLine("Updated Line SDK Config file.");
		}
		catch (Exception e)
		{
			Console.WriteLine("Something broken while updating Line SDK Config file : {0}", e.Message);
		}
	}
	
#endregion
}