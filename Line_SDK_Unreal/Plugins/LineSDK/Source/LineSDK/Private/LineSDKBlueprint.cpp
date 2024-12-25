#include "LineSDKBlueprint.h"

#include "LineSDK.h"

ULineSDKBlueprint::ULineSDKBlueprint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void ULineSDKBlueprint::Logger(const FString& Message)
{
	FLineSDK::Logger(Message);
}

void ULineSDKBlueprint::Login(const TArray<FString>& Scopes, FLineSDKResultListener ResultListener)
{
	FLineSDK::Login(Scopes, [ResultListener](const UResult* Result)
	{
		if (ResultListener.IsBound())
		{
			ResultListener.Execute(Result);
		}
	});
}

void ULineSDKBlueprint::LoginWithOption(
	const TArray<FString>& Scopes,
	const ULoginOption* Option,
	FLineSDKResultListener ResultListener
)
{
	FLineSDK::Login(Scopes, Option, [ResultListener](const UResult* Result)
	{
		if (ResultListener.IsBound())
		{
			ResultListener.Execute(Result);
		}
	});
}

void ULineSDKBlueprint::Logout(FLineSDKResultListener ResultListener)
{
	FLineSDK::Logout([ResultListener](const UResult* Result)
	{
		if (ResultListener.IsBound())
		{
			ResultListener.Execute(Result);
		}
	});
}

void ULineSDKBlueprint::RefreshAccessToken(FLineSDKResultListener ResultListener)
{
	FLineSDK::RefreshAccessToken([ResultListener](const UResult* Result)
	{
		if (ResultListener.IsBound())
		{
			ResultListener.Execute(Result);
		}
	});
}

void ULineSDKBlueprint::RevokeAccessToken(FLineSDKResultListener ResultListener)
{
	FLineSDK::RevokeAccessToken([ResultListener](const UResult* Result)
	{
		if (ResultListener.IsBound())
		{
			ResultListener.Execute(Result);
		}
	});
}

void ULineSDKBlueprint::VerifyAccessToken(FLineSDKResultListener ResultListener)
{
	FLineSDK::VerifyAccessToken([ResultListener](const UResult* Result)
	{
		if (ResultListener.IsBound())
		{
			ResultListener.Execute(Result);
		}
	});
}

void ULineSDKBlueprint::GetProfile(FLineSDKResultListener ResultListener)
{
	FLineSDK::GetProfile([ResultListener](const UResult* Result)
	{
		if (ResultListener.IsBound())
		{
			ResultListener.Execute(Result);
		}
	});
}

void ULineSDKBlueprint::GetBotFriendshipStatus(FLineSDKResultListener ResultListener)
{
	FLineSDK::GetBotFriendshipStatus([ResultListener](const UResult* Result)
	{
		if (ResultListener.IsBound())
		{
			ResultListener.Execute(Result);
		}
	});
}

UStoredAccessToken* ULineSDKBlueprint::GetCurrentAccessToken()
{
	return FLineSDK::GetCurrentAccessToken();
}