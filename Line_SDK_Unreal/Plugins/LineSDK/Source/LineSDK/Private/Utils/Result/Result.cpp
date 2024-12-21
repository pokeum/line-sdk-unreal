#include "Utils/Result/Result.h"

#include "Utils/Result/Result_AccessToken.h"
#include "Utils/Result/Result_LoginResult.h"

UResult* UResult::Ok_Return_UResult_LoginResult(ULoginResult* Value)
{
	UResult_LoginResult* ToReturn = NewObject<UResult_LoginResult>(GetTransientPackage(), UResult_LoginResult::StaticClass());
	ToReturn->Value = Value;
	ToReturn->Success = true;
	return ToReturn;
}

UResult* UResult::Ok_Return_UResult_AccessToken(UAccessToken* Value)
{
	UResult_AccessToken* ToReturn = NewObject<UResult_AccessToken>(GetTransientPackage(), UResult_AccessToken::StaticClass());
	ToReturn->Value = Value;
	ToReturn->Success = true;
	return ToReturn;
}


UResult* UResult::Error_Return_UResult(UError* Error)
{
	UResult* ToReturn = NewObject<UResult>(GetTransientPackage(), StaticClass());
	ToReturn->Error = Error;
	ToReturn->Success = false;
	return ToReturn;
}

void UResult::MatchError(const TFunction<void(const UError*)>& OnMatched) const
{
	if (OnMatched)
	{
		OnMatched(Error);
	}
}