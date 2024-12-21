#include "Model/Error.h"

#include "Utils/JSONUtils.h"

UError* UError::FromJson(const FString& Json)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Json);
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		int32 Code;
		JSONUtils::GetInt32Field(JsonObject, JSONKeys::Error::Code, Code);

		FString Message;
		JSONUtils::GetStringField(JsonObject, JSONKeys::Error::Message, Message);
		
		UError* Error = NewObject<UError>(GetTransientPackage(), StaticClass());
		Error->Code = Code;
		Error->Message = Message;
		return Error;
	}
	return nullptr;
}

int32 UError::GetCode() const { return Code; }

FString UError::GetMessage() const { return Message; }