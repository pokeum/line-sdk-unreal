#include "LineSDKInterfaceIOS.h"

LineSDKInterfaceIOS::LineSDKInterfaceIOS()
{
	
}

LineSDKInterfaceIOS::~LineSDKInterfaceIOS() override
{
	
}
	
void LineSDKInterfaceIOS::SetupSDK(const FString& ChannelId, const FString& UniversalLinkURL) override
{
	
}

void LineSDKInterfaceIOS::Login(const FString& Scope, bool OnlyWebLogin, const FString& BotPrompt, const FString& TokenNonce, const FString& Identifier) override
{
	
}

void LineSDKInterfaceIOS::Logout(const FString& Identifier) override
{
	
}

void LineSDKInterfaceIOS::RefreshAccessToken(const FString& Identifier) override
{
	
}

void LineSDKInterfaceIOS::RevokeAccessToken(const FString& Identifier) override
{
	
}

void LineSDKInterfaceIOS::VerifyAccessToken(const FString& Identifier) override
{
	
}

void LineSDKInterfaceIOS::GetProfile(const FString&  Identifier) override
{
	
}

void LineSDKInterfaceIOS::GetBotFriendshipStatus(const FString& Identifier) override
{
	
}

FString LineSDKInterfaceIOS::GetCurrentAccessToken() override
{
	return FString();
}