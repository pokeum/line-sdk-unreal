#include "Utils/Result/Result_Unit.h"

#include "LineSDK.h"

void UResult_Unit::MatchOk(const TFunction<void(const UUnit*)>& OnMatched) const
{
	if (IsFailure()) return;
	
	if (OnMatched)
	{
		OnMatched(Cast<UUnit>(Value));
	}
	else
	{
		FLineSDK::Logger(TEXT("Match callback is null!"));
	}
}

void UResult_Unit::Match(
	const TFunction<void(const UUnit*)>& OnMatchedOk,
	const TFunction<void(const UError*)>& OnMatchedError
) const
{
	MatchOk(OnMatchedOk);
	MatchError(OnMatchedError);
}