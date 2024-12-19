#include "LineSDK.h"

ULineSDKSettings::ULineSDKSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, ChannelID("")
	, UniversalLinkURL("")
{
}


void FLineSDK::SetupSDK(const FString& ChannelId, const FString& UniversalLinkURL)
{
	
}

void FLineSDK::Login(const FString& Scope, bool OnlyWebLogin, const FString& BotPrompt, const FString& TokenNonce, const FString& Identifier)
{
	
}

void FLineSDK::Logout(const FString& Identifier)
{
	
}

void FLineSDK::RefreshAccessToken(const FString& Identifier)
{
	
}

void FLineSDK::RevokeAccessToken(const FString& Identifier)
{
	
}

void FLineSDK::VerifyAccessToken(const FString& Identifier)
{
	
}

void FLineSDK::GetProfile(const FString&  Identifier)
{
	
}

void FLineSDK::GetBotFriendshipStatus(const FString& Identifier)
{
	
}

FString FLineSDK::GetCurrentAccessToken()
{
	return TEXT("");
}