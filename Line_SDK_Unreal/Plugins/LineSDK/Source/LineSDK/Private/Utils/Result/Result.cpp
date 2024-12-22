#include "Utils/Result/Result.h"

#include "LineSDK.h"
#include "Utils/Result/Result_AccessToken.h"
#include "Utils/Result/Result_LoginResult.h"

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