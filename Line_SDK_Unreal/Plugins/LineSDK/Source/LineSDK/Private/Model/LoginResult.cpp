#include "Model/LoginResult.h"

#include "Utils/JSONUtils.h"

ULoginResult* ULoginResult::FromJson(const FString& Json)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Json);
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		FString JsonString;
		JSONUtils::GetObjectField(JsonObject, JSONKeys::LoginResult::AccessToken, JsonString);
		UAccessToken* AccessToken = UAccessToken::FromJson(JsonString);
		
		FString Scope;
		JSONUtils::GetStringField(JsonObject, JSONKeys::LoginResult::Scope, Scope);

		JSONUtils::GetObjectField(JsonObject, JSONKeys::LoginResult::UserProfile, JsonString);
		UUserProfile* UserProfile = UUserProfile::FromJson(JsonString);
		
		bool FriendshipStatusChanged;
		JSONUtils::GetBoolField(JsonObject, JSONKeys::LoginResult::FriendshipStatusChanged, FriendshipStatusChanged);
		
		FString IDTokenNonce;
		JSONUtils::GetStringField(JsonObject, JSONKeys::LoginResult::IDTokenNonce, IDTokenNonce);
		
		ULoginResult* LoginResult = NewObject<ULoginResult>(GetTransientPackage(), StaticClass());
		LoginResult->AccessToken = AccessToken;
		LoginResult->Scope = Scope;
		LoginResult->UserProfile = UserProfile;
		LoginResult->FriendshipStatusChanged = FriendshipStatusChanged;
		LoginResult->IDTokenNonce = IDTokenNonce;
		return LoginResult;
	}
	return nullptr;
}

TSharedPtr<FJsonObject> ULoginResult::ToJsonObject() const
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	JsonObject->SetObjectField(JSONKeys::LoginResult::AccessToken, AccessToken->ToJsonObject());
	JsonObject->SetStringField(JSONKeys::LoginResult::Scope, Scope);
	JsonObject->SetObjectField(JSONKeys::LoginResult::UserProfile, UserProfile->ToJsonObject());
	JsonObject->SetBoolField(JSONKeys::LoginResult::FriendshipStatusChanged, FriendshipStatusChanged);
	JsonObject->SetStringField(JSONKeys::LoginResult::IDTokenNonce, IDTokenNonce);
	return JsonObject;
}

FString ULoginResult::ToJson() const
{
	return JSONUtils::ToJson(ToJsonObject());
}

UAccessToken* ULoginResult::GetAccessToken() const { return AccessToken; }

TArray<FString> ULoginResult::GetScopes() const
{
	TArray<FString> Scopes;
	Scope.ParseIntoArray(Scopes, TEXT(" "), true);
	return Scopes;
}

UUserProfile* ULoginResult::GetUserProfile() const { return UserProfile; }

bool ULoginResult::IsFriendshipStatusChanged() const { return FriendshipStatusChanged; }

FString ULoginResult::GetIdTokenNonce() const { return IDTokenNonce; }