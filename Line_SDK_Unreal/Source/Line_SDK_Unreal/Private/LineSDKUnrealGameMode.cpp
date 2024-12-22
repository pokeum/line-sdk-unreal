#include "LineSDKUnrealGameMode.h"

#include "LineSDK.h"

ALineSDKUnrealGameMode::ALineSDKUnrealGameMode()
{
	LINE_SDK_UNREAL_LOG(Warning, TEXT("LineSDKUnrealGameMode::ALineSDKUnrealGameMode"));

	FLineSDK::Login(
		TArray<FString>(),
		[](const UResult_LoginResult* Result)
		{
			Result->Match(
				[](const ULoginResult* LoginResult)
				{
				},
				[](const UError* Error)
				{
				}
			);
		}
	);
}
