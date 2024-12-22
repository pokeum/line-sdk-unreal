#include "LineSDKUnrealGameMode.h"

#include "LineSDK.h"

ALineSDKUnrealGameMode::ALineSDKUnrealGameMode()
{
	FLineSDK::Login(
		TArray<FString>(),
		[](const UResult_LoginResult* Result)
		{
			Result->Match(
				[](const ULoginResult* LoginResult)
				{
					FLineSDK::Logger(FString::Printf(
						TEXT("LoginResult: AccessToken={%s}"),
						*LoginResult->GetAccessToken()->GetAccessToken()));
				},
				[](const UError* Error)
				{
					FLineSDK::Logger(FString::Printf(
						TEXT("Error: Code={%d}, Message={%s}"),
						Error->GetCode(), *Error->GetMessage()));
				}
			);
		}
	);
}
