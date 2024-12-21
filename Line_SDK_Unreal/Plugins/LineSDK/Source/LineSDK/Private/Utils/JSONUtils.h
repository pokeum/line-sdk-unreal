#pragma once

#include "CoreMinimal.h"

namespace JSONKeys
{
	namespace CallbackPayload
	{
		static const FString Identifier		(TEXT("identifier"));
		static const FString Value			(TEXT("value"));
	}

	namespace AccessToken
	{
		static const FString AccessToken		(TEXT("access_token"));
		static const FString ExpiresIn			(TEXT("expires_in"));
		static const FString IdToken			(TEXT("id_token"));
		static const FString RefreshToken		(TEXT("refresh_token"));
		static const FString Scope				(TEXT("scope"));
		static const FString TokenType			(TEXT("token_type"));
	}

	namespace UserProfile
	{
		static const FString UserId				(TEXT("userId"));
		static const FString DisplayName		(TEXT("displayName"));
		static const FString PictureUrl			(TEXT("pictureUrl"));
		static const FString StatusMessage		(TEXT("statusMessage"));
	}

	namespace LoginResult
	{
		static const FString AccessToken				(TEXT("accessToken"));
		static const FString Scope						(TEXT("scope"));
		static const FString UserProfile				(TEXT("userProfile"));
		static const FString FriendshipStatusChanged	(TEXT("friendshipStatusChanged"));
		static const FString IDTokenNonce				(TEXT("IDTokenNonce"));
	}
	
	namespace Error
	{
		static const FString Code			(TEXT("code"));
		static const FString Message		(TEXT("message"));
	}
}

namespace JSONUtils
{
	bool GetStringField(const TSharedPtr<FJsonObject>& JsonObject, const FString& FieldName, FString& Field, const FString& Default = "");
	
	bool GetInt32Field(const TSharedPtr<FJsonObject>& JsonObject, const FString& FieldName, int32& Field, const int32& Default = 0);
	
	bool GetInt64Field(const TSharedPtr<FJsonObject>& JsonObject, const FString& FieldName, int64& Field, const int64& Default = 0);

	bool GetBoolField(const TSharedPtr<FJsonObject>& JsonObject, const FString& FieldName, bool& Field, const bool& Default = false);

	bool GetObjectField(const TSharedPtr<FJsonObject>& JsonObject, const FString& FieldName, FString& Field, const FString& Default = "{}");
}