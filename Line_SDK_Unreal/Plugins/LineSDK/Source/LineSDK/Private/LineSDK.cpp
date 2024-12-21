#include "LineSDK.h"

#include "API/LineAPI.h"
#include "LineSDKModule.h"

ULineSDKSettings::ULineSDKSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, ChannelID("")
	, UniversalLinkURL("")
{
}


void FLineSDK::Login(const TArray<FString>& Scopes, const TFunction<void(const UResult_LoginResult*)>& Function)
{
	Login(Scopes, ULoginOption(), Function);
}

void FLineSDK::Login(const TArray<FString>& Scopes, const ULoginOption& Option, const TFunction<void(const UResult_LoginResult*)>& Function)
{
	const FString Identifier = FLineAPI::AddAction(
		UFlattenAction::JsonFlatten(ULoginResult::StaticClass(), [Function](const UResult* Result)
		{
			if (Function)
			{
				Function(Cast<UResult_LoginResult>(Result));
			}
		})
	);
	
	const TArray<FString> FinalScopes = (Scopes.Num() > 0)? Scopes : TArray<FString>{ TEXT("profile") };
	
	FLineSDKModule::Get()->NativeInterface()->Login(
		FString::Join(FinalScopes, TEXT(" ")),
		Option.OnlyWebLogin,
		Option.BotPrompt,
		Option.IDTokenNonce,
		Identifier
	);
}

void FLineSDK::Logout()
{
	// TODO("Not yet implemented")
}

void FLineSDK::RefreshAccessToken(const TFunction<void(const UResult_AccessToken*)>& Function)
{
	const FString Identifier = FLineAPI::AddAction(
		UFlattenAction::JsonFlatten(UAccessToken::StaticClass(), [Function](const UResult* Result)
		{
			if (Function)
			{
				Function(Cast<UResult_AccessToken>(Result));
			}
		})
	);
	FLineSDKModule::Get()->NativeInterface()->RefreshAccessToken(Identifier);
}

void FLineSDK::RevokeAccessToken()
{
	// TODO("Not yet implemented")
}

void FLineSDK::VerifyAccessToken()
{
	// TODO("Not yet implemented")
}

void FLineSDK::GetProfile()
{
	// TODO("Not yet implemented")
}

void FLineSDK::GetBotFriendshipStatus()
{
	// TODO("Not yet implemented")
}

FString FLineSDK::GetCurrentAccessToken()
{
	return FLineSDKModule::Get()->NativeInterface()->GetCurrentAccessToken();
}