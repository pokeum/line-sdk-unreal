#include "Utils/Result/Result_LoginResult.h"

void UResult_LoginResult::MatchOk(const TFunction<void(const ULoginResult*)>& OnMatched) const
{
	if (OnMatched)
	{
		OnMatched(Cast<ULoginResult>(Value));
	}
}

void UResult_LoginResult::Match(
	const TFunction<void(const ULoginResult*)>& OnMatchedOk,
	const TFunction<void(const UError*)>& OnMatchedError
) const
{
	MatchOk(OnMatchedOk);
	MatchError(OnMatchedError);
}