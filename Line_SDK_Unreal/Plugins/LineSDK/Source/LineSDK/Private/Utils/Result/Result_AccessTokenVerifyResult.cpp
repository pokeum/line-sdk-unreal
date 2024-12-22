#include "Utils/Result/Result_AccessTokenVerifyResult.h"

#include "LineSDK.h"

void UResult_AccessTokenVerifyResult::MatchOk(const TFunction<void(const UAccessTokenVerifyResult*)>& OnMatched) const
{
	if (IsFailure()) return;
	
	if (OnMatched)
	{
		OnMatched(Cast<UAccessTokenVerifyResult>(Value));
	}
	else
	{
		FLineSDK::Logger(TEXT("Match callback is null!"));
	}
}

void UResult_AccessTokenVerifyResult::Match(
	const TFunction<void(const UAccessTokenVerifyResult*)>& OnMatchedOk,
	const TFunction<void(const UError*)>& OnMatchedError
) const
{
	MatchOk(OnMatchedOk);
	MatchError(OnMatchedError);
}