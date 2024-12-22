#include "Model/BotFriendshipStatus.h"

#include "Utils/JSONUtils.h"

UBotFriendshipStatus* UBotFriendshipStatus::FromJson(const FString& Json)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Json);
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		bool FriendFlag;
		JSONUtils::GetBoolField(JsonObject, JSONKeys::BotFriendshipStatus::FriendFlag, FriendFlag);

		UBotFriendshipStatus* ToReturn = NewObject<UBotFriendshipStatus>(GetTransientPackage(), StaticClass());
		ToReturn->FriendFlag = FriendFlag;
		return ToReturn;
	}
	return nullptr;
}

bool UBotFriendshipStatus::GetFriendFlag() const { return FriendFlag; }