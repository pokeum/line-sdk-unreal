#include "LineAPI.h"

TMap<FString, const UFlattenAction*> FLineAPI::Actions;

void FLineAPI::OnApiOk(const FString& Result)
{
	const UCallbackPayload* Payload = UCallbackPayload::FromJson(Result);
	const UFlattenAction* Action = PopActionFromPayload(Payload);
	if (Action != nullptr)
	{
		Action->CallOk(Payload->GetValue());
	}
}

void FLineAPI::OnApiError(const FString& Result)
{
	const UCallbackPayload* Payload = UCallbackPayload::FromJson(Result);
	const UFlattenAction* Action = PopActionFromPayload(Payload);
	if (Action != nullptr)
	{
		Action->CallError(Payload->GetValue());
	}
}

FString FLineAPI::AddAction(const UFlattenAction* Action)
{
	FString Identifier = FGuid::NewGuid().ToString();
	Actions.Emplace(Identifier, Action);
	return Identifier;
}

const UFlattenAction* FLineAPI::PopActionFromPayload(const UCallbackPayload* Payload)
{
	const FString Identifier = Payload->GetIdentifier();
	if (Actions.Contains(Identifier))
	{
		const UFlattenAction* Action = Actions[Identifier];
		Actions.Remove(Identifier);
		return Action;
	}
	return nullptr;
}