#include "LineSDKInterfaceIOS.h"

FLineSDKInterfaceIOS::FLineSDKInterfaceIOS()
{
	
}

FLineSDKInterfaceIOS::~FLineSDKInterfaceIOS()
{
	
}

void FLineSDKInterfaceIOS::Login(
	const FString& Identifier,
	const FString& Scope,
	bool OnlyWebLogin,
	const FNullableString& BotPrompt,
	const FNullableString& TokenNonce
)
{
	// TODO("Not yet implemented")
}
	
void FLineSDKInterfaceIOS::Logout(const FString& Identifier)
{
	// TODO("Not yet implemented")
}

void FLineSDKInterfaceIOS::RefreshAccessToken(const FString& Identifier)
{
	// TODO("Not yet implemented")
}

void FLineSDKInterfaceIOS::RevokeAccessToken(const FString& Identifier)
{
	// TODO("Not yet implemented")
}

void FLineSDKInterfaceIOS::VerifyAccessToken(const FString& Identifier)
{
	// TODO("Not yet implemented")
}

void FLineSDKInterfaceIOS::GetProfile(const FString&  Identifier)
{
	// TODO("Not yet implemented")
}

void FLineSDKInterfaceIOS::GetBotFriendshipStatus(const FString& Identifier)
{
	// TODO("Not yet implemented")
}

FString FLineSDKInterfaceIOS::GetCurrentAccessToken()
{
	// TODO("Not yet implemented")
	return FString();
}