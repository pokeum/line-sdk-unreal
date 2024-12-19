#include "LineSDKInterfaceAndroid.h"

LineSDKInterfaceAndroid::LineSDKInterfaceAndroid()
{
	
}

LineSDKInterfaceAndroid::~LineSDKInterfaceAndroid() override
{
	
}
	
void LineSDKInterfaceAndroid::SetupSDK(const FString& ChannelId, const FString& UniversalLinkURL) override
{
	
}

void LineSDKInterfaceAndroid::Login(const FString& Scope, bool OnlyWebLogin, const FString& BotPrompt, const FString& TokenNonce, const FString& Identifier) override
{
	
}

void LineSDKInterfaceAndroid::Logout(const FString& Identifier) override
{
	
}

void LineSDKInterfaceAndroid::RefreshAccessToken(const FString& Identifier) override
{
	
}

void LineSDKInterfaceAndroid::RevokeAccessToken(const FString& Identifier) override
{
	
}

void LineSDKInterfaceAndroid::VerifyAccessToken(const FString& Identifier) override
{
	
}

void LineSDKInterfaceAndroid::GetProfile(const FString&  Identifier) override
{
	
}

void LineSDKInterfaceAndroid::GetBotFriendshipStatus(const FString& Identifier) override
{
	
}

FString LineSDKInterfaceAndroid::GetCurrentAccessToken() override
{
	return FString();
}