#pragma once

#include "Model/AccessToken.h"
#include "Model/Error.h"
#include "Model/LoginResult.h"
#include "Result.generated.h"

UCLASS()
class LINESDK_API UResult : public UObject
{
	GENERATED_BODY()

public:
	static UResult* Ok_Return_UResult_LoginResult(ULoginResult* Value);
	
	static UResult* Ok_Return_UResult_AccessToken(UAccessToken* Value);

	
	static UResult* Error_Return_UResult(UError* Error);

	void MatchError(const TFunction<void(const UError*)>& OnMatched) const;

protected:
	UPROPERTY()
	UObject* Value;
	
	UPROPERTY()
	UError* Error;
	
	bool Success;
};
