#include "Model/StoredAccessToken.h"

#include "Utils/JSONUtils.h"

UStoredAccessToken* UStoredAccessToken::FromJson(const FString& Json)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Json);
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		FString	AccessToken;
		JSONUtils::GetStringField(JsonObject, JSONKeys::StoredAccessToken::AccessToken, AccessToken);
		
		int64 ExpiresIn;
		JSONUtils::GetInt64Field(JsonObject, JSONKeys::StoredAccessToken::ExpiresIn, ExpiresIn);
		
		UStoredAccessToken* ToReturn = NewObject<UStoredAccessToken>(GetTransientPackage(), StaticClass());
		ToReturn->AccessToken = AccessToken;
		ToReturn->ExpiresIn = ExpiresIn;
		return ToReturn;
	}
	return nullptr;
}

TSharedPtr<FJsonObject> UStoredAccessToken::ToJsonObject() const
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	JsonObject->SetStringField(JSONKeys::StoredAccessToken::AccessToken, AccessToken);
	JsonObject->SetNumberField(JSONKeys::StoredAccessToken::ExpiresIn, ExpiresIn);
	return JsonObject;
}

FString UStoredAccessToken::ToJson() const
{
	return JSONUtils::ToJson(ToJsonObject());
}

FString UStoredAccessToken::GetValue() const { return AccessToken; }

int64 UStoredAccessToken::GetExpiresIn() const { return ExpiresIn; }