#pragma once
#include "API/LineAPI.h"

namespace Helpers
{
	inline void IsInvalidRuntime(const FString& Identifier)
	{
		const auto ErrorJson = R"({"code":-1, "message":"platform not supported."})";
		const FString Result = UCallbackPayload::WrapValue(Identifier, ErrorJson);
		FLineAPI::OnApiError(Result);
	}
}