#include "LineSDK.h"

#include "API/LineAPI.h"
#include "LineSDKModule.h"

ULineSDKSettings::ULineSDKSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, ChannelID("")
	, UniversalLinkURL("")
{
}


void FLineSDK::Logger(const FString& Message)
{
	FLineSDKModule::Get()->NativeInterface()->Logger(Message);
}


void FLineSDK::Login(const TArray<FString>& Scopes, const TFunction<void(const UResult_LoginResult*)>& Function)
{
	Login(Scopes, ULoginOption::Construct(), Function);
}

void FLineSDK::Login(const TArray<FString>& Scopes, const ULoginOption* Option, const TFunction<void(const UResult_LoginResult*)>& Function)
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
		Identifier,
		FString::Join(FinalScopes, TEXT(" ")),
		Option->GetOnlyWebLogin(),
		Option->GetBotPrompt(),
		Option->GetIDTokenNonce()
	);
}

void FLineSDK::Logout(const TFunction<void(const UResult_Unit*)>& Function)
{
	const FString Identifier = FLineAPI::AddAction(
		UFlattenAction::JsonFlatten(UUnit::StaticClass(), [Function](const UResult* Result)
		{
			if (Function)
			{
				Function(Cast<UResult_Unit>(Result));
			}
		})
	);
	FLineSDKModule::Get()->NativeInterface()->Logout(Identifier);
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

void FLineSDK::RevokeAccessToken(const TFunction<void(const UResult_Unit*)>& Function)
{
	const FString Identifier = FLineAPI::AddAction(
		UFlattenAction::JsonFlatten(UUnit::StaticClass(), [Function](const UResult* Result)
		{
			if (Function)
			{
				Function(Cast<UResult_Unit>(Result));
			}
		})
	);
	FLineSDKModule::Get()->NativeInterface()->RevokeAccessToken(Identifier);
}

void FLineSDK::VerifyAccessToken(const TFunction<void(const UResult_AccessTokenVerifyResult*)>& Function)
{
	const FString Identifier = FLineAPI::AddAction(
		UFlattenAction::JsonFlatten(UAccessTokenVerifyResult::StaticClass(), [Function](const UResult* Result)
		{
			if (Function)
			{
				Function(Cast<UResult_AccessTokenVerifyResult>(Result));
			}
		})
	);
	FLineSDKModule::Get()->NativeInterface()->VerifyAccessToken(Identifier);
}

void FLineSDK::GetProfile(const TFunction<void(const UResult_UserProfile*)>& Function)
{
	const FString Identifier = FLineAPI::AddAction(
		UFlattenAction::JsonFlatten(UUserProfile::StaticClass(), [Function](const UResult* Result)
		{
			if (Function)
			{
				Function(Cast<UResult_UserProfile>(Result));
			}
		})
	);
	FLineSDKModule::Get()->NativeInterface()->GetProfile(Identifier);
}

void FLineSDK::GetBotFriendshipStatus(const TFunction<void(const UResult_BotFriendshipStatus*)>& Function)
{
	const FString Identifier = FLineAPI::AddAction(
		UFlattenAction::JsonFlatten(UBotFriendshipStatus::StaticClass(), [Function](const UResult* Result)
		{
			if (Function)
			{
				Function(Cast<UResult_BotFriendshipStatus>(Result));
			}
		})
	);
	FLineSDKModule::Get()->NativeInterface()->GetBotFriendshipStatus(Identifier);
}

FString FLineSDK::GetCurrentAccessToken()
{
	return FLineSDKModule::Get()->NativeInterface()->GetCurrentAccessToken();
}