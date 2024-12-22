#include "Utils/Result/Result_LoginResult.h"

#include "LineSDK.h"

void UResult_LoginResult::MatchOk(const TFunction<void(const ULoginResult*)>& OnMatched) const
{
	if (IsFailure()) return;
	
	if (OnMatched)
	{
		OnMatched(Cast<ULoginResult>(Value));
	}
	else
	{
		FLineSDK::Logger(TEXT("Match callback is null!"));
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