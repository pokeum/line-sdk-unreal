#include "LineSDKInterfaceIOS.h"

#include "API/LineAPI.h"
#include "IOS/IOSAppDelegate.h"
#include "LineSDKConfig.h"

#import <LineSDKWrapper/LineSDKWrapper.h>

static void LineSDKListenOpenURL(UIApplication* application, NSURL* url, NSString* sourceApplication, id annotation)
{
	UE_LOG(LogTemp, Display, TEXT("[LineSDK][OnOpenURL] URL={%s}"), *FString([url absoluteString]));
	[[LineSDKWrapper sharedInstance] application:application openURL:url];
}

FLineSDKInterfaceIOS::FLineSDKInterfaceIOS()
{
	// Unreal Bridge
	[LineSDKWrapper
		registerOnSuccess:^(NSString *message) {
			FLineAPI::OnApiOk(FString(message));
		}
		onFailure:^(NSString *message) {
			FLineAPI::OnApiError(FString(message));
		}];
	
	SetupSDK();

	// Handle the login result after your app is opened by the universal link
	FIOSCoreDelegates::OnOpenURL.AddStatic(&LineSDKListenOpenURL);
}

FLineSDKInterfaceIOS::~FLineSDKInterfaceIOS()
{
	
}

void FLineSDKInterfaceIOS::Logger(const FString& Message)
{
	UE_LOG(LogTemp, Display, TEXT("[LineSDK] %s"), *Message);
}

void FLineSDKInterfaceIOS::SetupSDK()
{
	[[LineSDKWrapper sharedInstance] setupChannelID:LineSDKConfig::ChannelID.GetNSString()
									  universalLink:LineSDKConfig::UniversalLinkURL.GetNSString()];
}

void FLineSDKInterfaceIOS::Login(
	const FString& Identifier,
	const FString& Scopes,
	bool OnlyWebLogin,
	const FNullableString& BotPrompt,
	const FNullableString& TokenNonce
)
{
	[[LineSDKWrapper sharedInstance] loginWithIdentifier:Identifier.GetNSString()
												  scopes:Scopes.GetNSString()
											onlyWebLogin:(OnlyWebLogin ? YES : NO)
											   botPrompt:BotPrompt.GetNSString()
											IDTokenNonce:TokenNonce.GetNSString()];
}
	
void FLineSDKInterfaceIOS::Logout(const FString& Identifier)
{
	[[LineSDKWrapper sharedInstance] logoutWithIdentifier:Identifier.GetNSString()];
}

void FLineSDKInterfaceIOS::RefreshAccessToken(const FString& Identifier)
{
	[[LineSDKWrapper sharedInstance] refreshAccessTokenWithIdentifier:Identifier.GetNSString()];
}

void FLineSDKInterfaceIOS::RevokeAccessToken(const FString& Identifier)
{
	[[LineSDKWrapper sharedInstance] revokeAccessTokenWithIdentifier:Identifier.GetNSString()];
}

void FLineSDKInterfaceIOS::VerifyAccessToken(const FString& Identifier)
{
	[[LineSDKWrapper sharedInstance] verifyAccessTokenWithIdentifier:Identifier.GetNSString()];
}

void FLineSDKInterfaceIOS::GetProfile(const FString&  Identifier)
{
	[[LineSDKWrapper sharedInstance] getProfileWithIdentifier:Identifier.GetNSString()];
}

void FLineSDKInterfaceIOS::GetBotFriendshipStatus(const FString& Identifier)
{
	[[LineSDKWrapper sharedInstance] getBotFriendshipStatusWithIdentifier:Identifier.GetNSString()];
}

FString FLineSDKInterfaceIOS::GetCurrentAccessToken()
{
	return FString([[LineSDKWrapper sharedInstance] currentAccessToken]);
}