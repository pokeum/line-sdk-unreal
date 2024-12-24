#pragma once

#include "Response.h"
#include "Model/Error.h"
#include "Result.generated.h"

UCLASS()
class LINESDK_API UResult : public UObject
{
	GENERATED_BODY()

public:
	static UResult* HandleOk(UResponse* Value);

	static UResult* HandleError(UError* Error);

	void MatchOk(const TFunction<void(const UResponse*)>& OnMatched) const;

	void MatchError(const TFunction<void(const UError*)>& OnMatched) const;

	void Match(const TFunction<void(const UResponse*)>& OnMatchedOk, const TFunction<void(const UError*)>& OnMatchedError) const;

private:
	UPROPERTY()
	UResponse* Value;
	
	UPROPERTY()
	UError* Error;

	UPROPERTY()
	bool bSuccess;
	
	bool IsSuccess() const;
	
	bool IsFailure() const;
};
