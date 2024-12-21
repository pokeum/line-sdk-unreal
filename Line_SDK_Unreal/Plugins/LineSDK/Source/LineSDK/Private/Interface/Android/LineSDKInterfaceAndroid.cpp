#include "LineSDKInterfaceAndroid.h"

FLineSDKInterfaceAndroid::FLineSDKInterfaceAndroid()
{
	
}

FLineSDKInterfaceAndroid::~FLineSDKInterfaceAndroid()
{
	
}

void FLineSDKInterfaceAndroid::Login(
	const FString& Scope,
	bool OnlyWebLogin,
	const FNullableString& BotPrompt,
	const FNullableString& TokenNonce,
	const FString& Identifier
)
{
	// TODO("Not yet implemented")
}
	
void FLineSDKInterfaceAndroid::Logout(const FString& Identifier)
{
	// TODO("Not yet implemented")
}

void FLineSDKInterfaceAndroid::RefreshAccessToken(const FString& Identifier)
{
	// TODO("Not yet implemented")
}

void FLineSDKInterfaceAndroid::RevokeAccessToken(const FString& Identifier)
{
	// TODO("Not yet implemented")
}

void FLineSDKInterfaceAndroid::VerifyAccessToken(const FString& Identifier)
{
	// TODO("Not yet implemented")
}

void FLineSDKInterfaceAndroid::GetProfile(const FString&  Identifier)
{
	// TODO("Not yet implemented")
}

void FLineSDKInterfaceAndroid::GetBotFriendshipStatus(const FString& Identifier)
{
	// TODO("Not yet implemented")
}

FString FLineSDKInterfaceAndroid::GetCurrentAccessToken()
{
	// TODO("Not yet implemented")
	return FString();
}