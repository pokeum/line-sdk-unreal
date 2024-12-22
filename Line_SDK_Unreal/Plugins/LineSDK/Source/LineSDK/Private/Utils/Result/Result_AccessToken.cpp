#include "Utils/Result/Result_AccessToken.h"

#include "LineSDK.h"

void UResult_AccessToken::MatchOk(const TFunction<void(const UAccessToken*)>& OnMatched) const
{
	if (IsFailure()) return;
	
	if (OnMatched)
	{
		OnMatched(Cast<UAccessToken>(Value));
	}
	else
	{
		FLineSDK::Logger(TEXT("Match callback is null!"));
	}
}

void UResult_AccessToken::Match(
	const TFunction<void(const UAccessToken*)>& OnMatchedOk,
	const TFunction<void(const UError*)>& OnMatchedError
) const
{
	MatchOk(OnMatchedOk);
	MatchError(OnMatchedError);
}