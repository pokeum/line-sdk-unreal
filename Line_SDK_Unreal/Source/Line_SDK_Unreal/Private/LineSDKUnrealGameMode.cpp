#include "LineSDKUnrealGameMode.h"

#include "LineSDK.h"

ALineSDKUnrealGameMode::ALineSDKUnrealGameMode()
{
	LINE_SDK_UNREAL_LOG(Warning, TEXT("LineSDKUnrealGameMode::ALineSDKUnrealGameMode"));

	FLineSDK::RefreshAccessToken([](const UResult_AccessToken* Result)
	{
		Result->Match(
			[](const UAccessToken* AccessToken)
			{
			},
			[](const UError* Error)
			{
			}
		);
	});
}