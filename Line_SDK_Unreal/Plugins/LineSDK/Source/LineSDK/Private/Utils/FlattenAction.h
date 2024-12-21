#pragma once

#include "Utils/Result/Result.h"
#include "FlattenAction.generated.h"

UCLASS()
class LINESDK_API UFlattenAction : public UObject
{
	GENERATED_BODY()

public:
	static UFlattenAction* JsonFlatten(TSubclassOf<UObject> ClassType, const TFunction<void(const UResult*)>& Function);

	void CallOk(const FString& String) const;
	void CallError(const FString& String) const;

private:
	TFunction<void(const FString&)> SuccessAction;
	TFunction<void(const FString&)> FailureAction;

	void Set(const TFunction<void(const FString&)>& OnSuccess, const TFunction<void(const FString&)>& OnFailure);
};