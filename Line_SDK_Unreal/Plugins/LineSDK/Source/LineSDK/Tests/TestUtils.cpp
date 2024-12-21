#include "TestUtils.h"

DEFINE_LOG_CATEGORY(LineSDKTest);

// https://unrealcommunity.wiki/6100e80f9c9d1a89e0c30e12
FString TestUtils::GetStringFromFile(const FString& FileName)
{
	FString File = FPaths::ProjectPluginsDir();
	File.Append("LineSDK/Source/LineSDK/Tests/Resources/").Append(FileName);

	// We will use this FileManager to deal with the file.
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	FString FileContent;
	// Always first check if the file that you want to manipulate exist.
	if (FileManager.FileExists(*File))
	{
		// We use the LoadFileToString to load the file into
		if (FFileHelper::LoadFileToString(FileContent, *File, FFileHelper::EHashOptions::None))
		{
			LINE_SDK_TEST_LOG(TEXT("[TestUtils::GetStringFromFile]: Text From File:\n%s"), *FileContent);
		}
		else
		{
			LINE_SDK_TEST_LOG(TEXT("[TestUtils::GetStringFromFile]: Did not load text from file"));
		}
	}
	else
	{
		LINE_SDK_TEST_LOG(TEXT("[TestUtils::GetStringFromFile]: ERROR: Can not read the file because it was not found."));
		LINE_SDK_TEST_LOG(TEXT("[TestUtils::GetStringFromFile]: Expected file location: %s"), *File);
	}
	return FileContent;
}
