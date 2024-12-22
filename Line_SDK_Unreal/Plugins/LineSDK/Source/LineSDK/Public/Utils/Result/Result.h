#pragma once

#include "Model/AccessToken.h"
#include "Model/AccessTokenVerifyResult.h"
#include "Model/BotFriendshipStatus.h"
#include "Model/Error.h"
#include "Model/LoginResult.h"
#include "Model/Unit.h"
#include "Result.generated.h"

UCLASS()
class LINESDK_API UResult : public UObject
{
	GENERATED_BODY()

public:
	// LoginResult
	static UResult* Ok_Return_UResult_LoginResult(ULoginResult* Value);
	static UResult* Error_Return_UResult_LoginResult(UError* Error);

	// AccessToken
	static UResult* Ok_Return_UResult_AccessToken(UAccessToken* Value);
	static UResult* Error_Return_UResult_AccessToken(UError* Error);

	// AccessTokenVerifyResult
	static UResult* Ok_Return_UResult_AccessTokenVerifyResult(UAccessTokenVerifyResult* Value);
	static UResult* Error_Return_UResult_AccessTokenVerifyResult(UError* Error);
	
	// UserProfile
	static UResult* Ok_Return_UResult_UserProfile(UUserProfile* Value);
	static UResult* Error_Return_UResult_UserProfile(UError* Error);

	// BotFriendshipStatus
	static UResult* Ok_Return_UResult_BotFriendshipStatus(UBotFriendshipStatus* Value);
	static UResult* Error_Return_UResult_BotFriendshipStatus(UError* Error);

	// Unit
	static UResult* Ok_Return_UResult_Unit(UUnit* Value);
	static UResult* Error_Return_UResult_Unit(UError* Error);

	void MatchError(const TFunction<void(const UError*)>& OnMatched) const;

protected:
	UPROPERTY()
	UObject* Value;
	
	UPROPERTY()
	UError* Error;

	bool IsSuccess() const;
	
	bool IsFailure() const;

private:
	bool bSuccess;
};
