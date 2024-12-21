#include "Model/AccessToken.h"

#include "Utils/JSONUtils.h"

UAccessToken* UAccessToken::FromJson(const FString& Json)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Json);
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		FString	AccessToken;
		JSONUtils::GetStringField(JsonObject, JSONKeys::AccessToken::AccessToken, AccessToken);
		
		int64 ExpiresIn;
		JSONUtils::GetInt64Field(JsonObject, JSONKeys::AccessToken::ExpiresIn, ExpiresIn);
		
		FString	IdToken;
		JSONUtils::GetStringField(JsonObject, JSONKeys::AccessToken::IdToken, IdToken);
		
		FString RefreshToken;
		JSONUtils::GetStringField(JsonObject, JSONKeys::AccessToken::RefreshToken, RefreshToken);

		FString Scope;
		JSONUtils::GetStringField(JsonObject, JSONKeys::AccessToken::Scope, Scope);
		
		FString TokenType;
		JSONUtils::GetStringField(JsonObject, JSONKeys::AccessToken::TokenType, TokenType);

		UAccessToken* ToReturn = NewObject<UAccessToken>(GetTransientPackage(), StaticClass());
		ToReturn->AccessToken = AccessToken;
		ToReturn->ExpiresIn = ExpiresIn;
		ToReturn->IdToken = IdToken;
		ToReturn->RefreshToken = RefreshToken;
		ToReturn->Scope = Scope;
		ToReturn->TokenType = TokenType;
		return ToReturn;
	}
	return nullptr;
}

FString UAccessToken::GetAccessToken() const { return AccessToken; }

int64 UAccessToken::GetExpiresIn() const { return ExpiresIn; }

FString UAccessToken::GetIdToken() const { return IdToken; }

FString UAccessToken::GetRefreshToken() const { return RefreshToken; }

FString UAccessToken::GetScope() const { return Scope; }

FString UAccessToken::GetTokenType() const { return TokenType; }