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

UAccessToken* ULoginResult::GetAccessToken() const { return AccessToken; }

FString ULoginResult::GetScope() const { return Scope; }

UUserProfile* ULoginResult::GetUserProfile() const { return UserProfile; }

bool ULoginResult::GetFriendshipStatusChanged() const { return FriendshipStatusChanged; }

FString ULoginResult::GetIDTokenNonce() const { return IDTokenNonce; }