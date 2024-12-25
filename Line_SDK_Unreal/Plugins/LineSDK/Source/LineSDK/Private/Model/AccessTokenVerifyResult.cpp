#include "Model/AccessTokenVerifyResult.h"

#include "Utils/JSONUtils.h"

UAccessTokenVerifyResult* UAccessTokenVerifyResult::FromJson(const FString& Json)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Json);
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		FString ClientId;
		JSONUtils::GetStringField(JsonObject, JSONKeys::AccessTokenVerifyResult::ClientId, ClientId);

		FString Scope;
		JSONUtils::GetStringField(JsonObject, JSONKeys::AccessTokenVerifyResult::Scope, Scope);

		int64 ExpiresIn;
		JSONUtils::GetInt64Field(JsonObject, JSONKeys::AccessTokenVerifyResult::ExpiresIn, ExpiresIn);

		UAccessTokenVerifyResult* ToReturn = NewObject<UAccessTokenVerifyResult>(GetTransientPackage(), StaticClass());
		ToReturn->ClientId = ClientId;
		ToReturn->Scope = Scope;
		ToReturn->ExpiresIn = ExpiresIn;
		return ToReturn;
	}
	return nullptr;
}

TSharedPtr<FJsonObject> UAccessTokenVerifyResult::ToJsonObject() const
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	JsonObject->SetStringField(JSONKeys::AccessTokenVerifyResult::ClientId, ClientId);
	JsonObject->SetStringField(JSONKeys::AccessTokenVerifyResult::Scope, Scope);
	JsonObject->SetNumberField(JSONKeys::AccessTokenVerifyResult::ExpiresIn, ExpiresIn);
	return JsonObject;
}

FString UAccessTokenVerifyResult::ToJson() const
{
	return JSONUtils::ToJson(ToJsonObject());
}

FString UAccessTokenVerifyResult::GetChannelId() const { return ClientId; }

FString UAccessTokenVerifyResult::GetScope() const { return Scope; }

int64 UAccessTokenVerifyResult::GetExpiresIn() const { return ExpiresIn; }