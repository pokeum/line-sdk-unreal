#pragma once

#include "Result.h"
#include "Model/Error.h"
#include "Model/Unit.h"
#include "Result_Unit.generated.h"

UCLASS()
class LINESDK_API UResult_Unit : public UResult
{
	GENERATED_BODY()

public:
	void MatchOk(const TFunction<void(const UUnit*)>& OnMatched) const;

	void Match(
		const TFunction<void(const UUnit*)>& OnMatchedOk,
		const TFunction<void(const UError*)>& OnMatchedError
	) const;
};