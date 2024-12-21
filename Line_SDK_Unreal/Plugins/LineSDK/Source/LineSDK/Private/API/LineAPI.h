#pragma once

#include "Model/CallbackPayload.h"
#include "Utils/FlattenAction.h"

class LINESDK_API FLineAPI
{
public:
	static FString AddAction(const UFlattenAction* Action);
	
	static void OnApiOk(const FString& Result);
	static void OnApiError(const FString& Result);

private:
	static TMap<FString, const UFlattenAction*> Actions;
	static const UFlattenAction* PopActionFromPayload(const UCallbackPayload* Payload);	
};