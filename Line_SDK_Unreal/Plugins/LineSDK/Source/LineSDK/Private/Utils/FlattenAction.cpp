#include "FlattenAction.h"

#include "Model/AccessToken.h"
#include "Model/AccessTokenVerifyResult.h"
#include "Model/BotFriendshipStatus.h"
#include "Model/LoginResult.h"

UFlattenAction* UFlattenAction::JsonFlatten(const TSubclassOf<UResponse>& ResponseType, const TFunction<void(const UResult*)>& Function)
{
	UFlattenAction* Action = NewObject<UFlattenAction>(GetTransientPackage(), StaticClass());
	Action->Set(
		/** On Success */
		[ResponseType, Function](const FString& JsonString)
		{
			if (Function == nullptr) return;

			UResponse* Response;
			
			// ResponseType에 따라 분기 처리
			if (ResponseType->IsChildOf(ULoginResult::StaticClass()))
			{
				Response = ULoginResult::FromJson(JsonString);
			}
			else if (ResponseType->IsChildOf(UAccessToken::StaticClass()))
			{
				Response = UAccessToken::FromJson(JsonString);
			}
			else if (ResponseType->IsChildOf(UAccessTokenVerifyResult::StaticClass()))
			{
				Response = UAccessTokenVerifyResult::FromJson(JsonString);
			}
			else if (ResponseType->IsChildOf(UUserProfile::StaticClass()))
			{
				Response = UUserProfile::FromJson(JsonString);
			}
			else if (ResponseType->IsChildOf(UBotFriendshipStatus::StaticClass()))
			{
				Response = UBotFriendshipStatus::FromJson(JsonString);
			}
			else { Response = UResponse::Unit(); }
			
			Function(UResult::HandleOk(Response));
		},
		/** On Failure */
		[Function](const FString& JsonString)
		{
			if (Function == nullptr) return;
			Function(UResult::HandleError(UError::FromJson(JsonString)));
		}
	);
	return Action;
}

void UFlattenAction::CallOk(const FString& String) const
{
	if (SuccessAction)
	{
		SuccessAction(String);
	}
}

void UFlattenAction::CallError(const FString& String) const
{
	if (FailureAction)
	{
		FailureAction(String);	
	}
}

void UFlattenAction::Set(const TFunction<void(const FString&)>& OnSuccess, const TFunction<void(const FString&)>& OnFailure)
{
	this->SuccessAction = OnSuccess;
	this->FailureAction = OnFailure;
}