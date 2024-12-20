#include "LineSDKInterfaceAndroid.h"

#include "Model/CallbackPayload.h"

LineSDKInterfaceAndroid::LineSDKInterfaceAndroid()
{
	
}

LineSDKInterfaceAndroid::~LineSDKInterfaceAndroid()
{
	
}
	
void LineSDKInterfaceAndroid::SetupSDK(const FString& ChannelId, const FString& UniversalLinkURL)
{
	
}

void LineSDKInterfaceAndroid::Login(const FString& Scope, bool OnlyWebLogin, const FString& BotPrompt, const FString& TokenNonce, const FString& Identifier)
{
	
}

void LineSDKInterfaceAndroid::Logout(const FString& Identifier)
{
	
}

void LineSDKInterfaceAndroid::RefreshAccessToken(const FString& Identifier)
{
	
}

void LineSDKInterfaceAndroid::RevokeAccessToken(const FString& Identifier)
{
	
}

void LineSDKInterfaceAndroid::VerifyAccessToken(const FString& Identifier)
{
	
}

void LineSDKInterfaceAndroid::GetProfile(const FString&  Identifier)
{
	
}

void LineSDKInterfaceAndroid::GetBotFriendshipStatus(const FString& Identifier)
{
	
}

FString LineSDKInterfaceAndroid::GetCurrentAccessToken()
{
	return FString();
}

void LineSDKInterfaceAndroid::OnApiOk(const FString& Result)
{
	UCallbackPayload* Payload = UCallbackPayload::FromJson(Result);
}

void LineSDKInterfaceAndroid::OnApiError(const FString& Result)
{
	UCallbackPayload* Payload = UCallbackPayload::FromJson(Result);
}