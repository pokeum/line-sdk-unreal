#include "Utils/Result.h"

#include "LineSDK.h"

UResult* UResult::HandleOk(UResponse* Value)
{
	UResult* ToReturn = NewObject<UResult>(GetTransientPackage(), StaticClass());
	ToReturn->Value = Value;
	ToReturn->bSuccess = true;
	return ToReturn;
}

UResult* UResult::HandleError(UError* Error)
{
	UResult* ToReturn = NewObject<UResult>(GetTransientPackage(), StaticClass());
	ToReturn->Error = Error;
	ToReturn->bSuccess = false;
	return ToReturn;
}

void UResult::MatchOk(const TFunction<void(const UResponse*)>& OnMatched) const
{
	if (IsFailure()) return;
	
	if (OnMatched)
	{
		OnMatched(Value);
	}
	else
	{
		FLineSDK::Logger(TEXT("Match callback is null!"));
	}
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

void UResult::Match(const TFunction<void(const UResponse*)>& OnMatchedOk, const TFunction<void(const UError*)>& OnMatchedError) const
{
	MatchOk(OnMatchedOk);
	MatchError(OnMatchedError);
}

bool UResult::IsSuccess() const { return bSuccess; }
	
bool UResult::IsFailure() const { return !bSuccess; }