#include "FlattenAction.h"

#include "Model/AccessToken.h"
#include "Model/LoginResult.h"

UFlattenAction* UFlattenAction::JsonFlatten(TSubclassOf<UObject> ClassType, const TFunction<void(const UResult*)>& Function)
{
	UFlattenAction* Action = NewObject<UFlattenAction>(GetTransientPackage(), StaticClass());
	Action->Set(
		[ClassType, Function](const FString& JsonString)
		{
			if (Function == nullptr) return;
		
			// ClassType에 따라 분기 처리
			if (ClassType->IsChildOf(ULoginResult::StaticClass()))
			{
				Function(UResult::Ok_Return_UResult_LoginResult(ULoginResult::FromJson(JsonString)));
			}
			else if (ClassType->IsChildOf(UAccessToken::StaticClass()))
			{
				Function(UResult::Ok_Return_UResult_AccessToken(UAccessToken::FromJson(JsonString)));
			}
		},
		[Function](const FString& JsonString)
		{
			if (Function == nullptr) return;
			
			Function(UResult::Error_Return_UResult(UError::FromJson(JsonString)));
		}
	);
	return Action;
}

void UFlattenAction::CallOk(const FString& String) const
{
	SuccessAction(String);
}

void UFlattenAction::CallError(const FString& String) const
{
	FailureAction(String);
}

void UFlattenAction::Set(const TFunction<void(const FString&)>& OnSuccess, const TFunction<void(const FString&)>& OnFailure)
{
	this->SuccessAction = OnSuccess;
	this->FailureAction = OnFailure;
}