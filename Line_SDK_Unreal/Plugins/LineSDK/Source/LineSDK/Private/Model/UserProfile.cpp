#include "Model/UserProfile.h"

#include "Utils/JSONUtils.h"

UUserProfile* UUserProfile::FromJson(const FString& Json)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Json);
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		FString UserId;
		JSONUtils::GetStringField(JsonObject, JSONKeys::UserProfile::UserId, UserId);

		FString DisplayName;
		JSONUtils::GetStringField(JsonObject, JSONKeys::UserProfile::DisplayName, DisplayName);

		FString PictureUrl;
		JSONUtils::GetStringField(JsonObject, JSONKeys::UserProfile::PictureUrl, PictureUrl);

		FString StatusMessage;
		JSONUtils::GetStringField(JsonObject, JSONKeys::UserProfile::StatusMessage, StatusMessage);
		
		UUserProfile* UserProfile = NewObject<UUserProfile>(GetTransientPackage(), StaticClass());
		UserProfile->UserId = UserId;
		UserProfile->DisplayName = DisplayName;
		UserProfile->PictureUrl = PictureUrl;
		UserProfile->StatusMessage = StatusMessage;
		return UserProfile;
	}
	return nullptr;
}

TSharedPtr<FJsonObject> UUserProfile::ToJsonObject() const
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	JsonObject->SetStringField(JSONKeys::UserProfile::UserId, UserId);
	JsonObject->SetStringField(JSONKeys::UserProfile::DisplayName, DisplayName);
	JsonObject->SetStringField(JSONKeys::UserProfile::PictureUrl, PictureUrl);
	JsonObject->SetStringField(JSONKeys::UserProfile::StatusMessage, StatusMessage);
	return JsonObject;
}

FString UUserProfile::ToJson() const
{
	return JSONUtils::ToJson(ToJsonObject());
}

FString UUserProfile::GetUserId() const { return UserId; }

FString UUserProfile::GetDisplayName() const { return DisplayName; }

FString UUserProfile::GetStatusMessage() const { return StatusMessage; }

FString UUserProfile::GetPictureUrl() const { return PictureUrl; }

FString UUserProfile::GetPictureUrlLarge() const
{
	if (PictureUrl.IsEmpty())
	{
		return TEXT("");
	}
	return PictureUrl + TEXT("/large");
}

FString UUserProfile::GetPictureUrlSmall() const
{
	if (PictureUrl.IsEmpty())
	{
		return TEXT("");
	}
	return PictureUrl + TEXT("/small");
}