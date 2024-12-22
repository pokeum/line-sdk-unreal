#include "Utils/Result/Result.h"

#include "LineSDK.h"
#include "Utils/Result/Result_AccessToken.h"
#include "Utils/Result/Result_AccessTokenVerifyResult.h"
#include "Utils/Result/Result_BotFriendshipStatus.h"
#include "Utils/Result/Result_LoginResult.h"
#include "Utils/Result/Result_Unit.h"
#include "Utils/Result/Result_UserProfile.h"

#pragma region LoginResult

UResult* UResult::Ok_Return_UResult_LoginResult(ULoginResult* Value)
{
	UResult_LoginResult* ToReturn = NewObject<UResult_LoginResult>(GetTransientPackage(), UResult_LoginResult::StaticClass());
	ToReturn->Value = Value;
	ToReturn->bSuccess = true;
	return ToReturn;
}

UResult* UResult::Error_Return_UResult_LoginResult(UError* Error)
{
	UResult_LoginResult* ToReturn = NewObject<UResult_LoginResult>(GetTransientPackage(), UResult_LoginResult::StaticClass());
	ToReturn->Error = Error;
	ToReturn->bSuccess = false;
	return ToReturn;
}

#pragma endregion

#pragma region AccessToken

UResult* UResult::Ok_Return_UResult_AccessToken(UAccessToken* Value)
{
	UResult_AccessToken* ToReturn = NewObject<UResult_AccessToken>(GetTransientPackage(), UResult_AccessToken::StaticClass());
	ToReturn->Value = Value;
	ToReturn->bSuccess = true;
	return ToReturn;
}

UResult* UResult::Error_Return_UResult_AccessToken(UError* Error)
{
	UResult_AccessToken* ToReturn = NewObject<UResult_AccessToken>(GetTransientPackage(), UResult_AccessToken::StaticClass());
	ToReturn->Error = Error;
	ToReturn->bSuccess = false;
	return ToReturn;
}

#pragma endregion

#pragma region AccessTokenVerifyResult

UResult* UResult::Ok_Return_UResult_AccessTokenVerifyResult(UAccessTokenVerifyResult* Value)
{
	UResult_AccessTokenVerifyResult* ToReturn =
		NewObject<UResult_AccessTokenVerifyResult>(GetTransientPackage(), UResult_AccessTokenVerifyResult::StaticClass());
	ToReturn->Value = Value;
	ToReturn->bSuccess = true;
	return ToReturn;
}

UResult* UResult::Error_Return_UResult_AccessTokenVerifyResult(UError* Error)
{
	UResult_AccessTokenVerifyResult* ToReturn =
		NewObject<UResult_AccessTokenVerifyResult>(GetTransientPackage(), UResult_AccessTokenVerifyResult::StaticClass());
	ToReturn->Error = Error;
	ToReturn->bSuccess = false;
	return ToReturn;
}

#pragma endregion

#pragma region UserProfile

UResult* UResult::Ok_Return_UResult_UserProfile(UUserProfile* Value)
{
	UResult_UserProfile* ToReturn = NewObject<UResult_UserProfile>(GetTransientPackage(), UResult_UserProfile::StaticClass());
	ToReturn->Value = Value;
	ToReturn->bSuccess = true;
	return ToReturn;
}

UResult* UResult::Error_Return_UResult_UserProfile(UError* Error)
{
	UResult_UserProfile* ToReturn = NewObject<UResult_UserProfile>(GetTransientPackage(), UResult_UserProfile::StaticClass());
	ToReturn->Error = Error;
	ToReturn->bSuccess = false;
	return ToReturn;
}

#pragma endregion

#pragma region BotFriendshipStatus

UResult* UResult::Ok_Return_UResult_BotFriendshipStatus(UBotFriendshipStatus* Value)
{
	UResult_BotFriendshipStatus* ToReturn =
		NewObject<UResult_BotFriendshipStatus>(GetTransientPackage(), UResult_BotFriendshipStatus::StaticClass());
	ToReturn->Value = Value;
	ToReturn->bSuccess = true;
	return ToReturn;
}

UResult* UResult::Error_Return_UResult_BotFriendshipStatus(UError* Error)
{
	UResult_BotFriendshipStatus* ToReturn =
		NewObject<UResult_BotFriendshipStatus>(GetTransientPackage(), UResult_BotFriendshipStatus::StaticClass());
	ToReturn->Error = Error;
	ToReturn->bSuccess = false;
	return ToReturn;
}

#pragma endregion

#pragma region Unit

UResult* UResult::Ok_Return_UResult_Unit(UUnit* Value)
{
	UResult_Unit* ToReturn = NewObject<UResult_Unit>(GetTransientPackage(), UResult_Unit::StaticClass());
	ToReturn->Value = Value;
	ToReturn->bSuccess = true;
	return ToReturn;
}

UResult* UResult::Error_Return_UResult_Unit(UError* Error)
{
	UResult_Unit* ToReturn = NewObject<UResult_Unit>(GetTransientPackage(), UResult_Unit::StaticClass());
	ToReturn->Error = Error;
	ToReturn->bSuccess = false;
	return ToReturn;
}

#pragma endregion

void UResult::MatchError(const TFunction<void(const UError*)>& OnMatched) const
{
	if (IsSuccess()) return;
	
	if (OnMatched)
	{
		OnMatched(Error);
	}
	else
	{
		FLineSDK::Logger(TEXT("Match callback is null!"));
	}
}

bool UResult::IsSuccess() const { return bSuccess; }
	
bool UResult::IsFailure() const { return !bSuccess; }