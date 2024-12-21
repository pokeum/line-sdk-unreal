#include "Utils/Result/Result_AccessToken.h"

void UResult_AccessToken::MatchOk(const TFunction<void(const UAccessToken*)>& OnMatched) const
{
	if (OnMatched)
	{
		OnMatched(Cast<UAccessToken>(Value));
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