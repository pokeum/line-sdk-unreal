#include "Model/CallbackPayload.h"

#include "Utils/JSONUtils.h"

UCallbackPayload* UCallbackPayload::FromJson(const FString& Json)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Json);
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		FString Identifier;	// Required
		if (!JSONUtils::GetStringField(JsonObject, JSONKeys::CallbackPayload::Identifier, Identifier))
		{
			return nullptr;
		}
	
		FString Value;	// Required
		if (!JSONUtils::GetStringField(JsonObject, JSONKeys::CallbackPayload::Value, Value))
		{
			return nullptr;
		}

		UCallbackPayload* Payload = NewObject<UCallbackPayload>(GetTransientPackage(), StaticClass());
		Payload->Identifier = Identifier;
		Payload->Value = Value;
		return Payload;
	}
	return nullptr;
}

FString UCallbackPayload::WrapValue(const FString& Identifier, const FString& Value)
{
	UCallbackPayload* Payload = NewObject<UCallbackPayload>(GetTransientPackage(), StaticClass());
	Payload->Identifier = Identifier;
	Payload->Value = Value;
	return Payload->ToJson();
}

FString UCallbackPayload::ToJson() const
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	JsonObject->SetStringField(JSONKeys::CallbackPayload::Identifier, Identifier);
	JsonObject->SetStringField(JSONKeys::CallbackPayload::Value, Value);
	
	FString JsonString;
	const TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	if (FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer))
	{
		return JsonString;
	}
	return TEXT("");
}

FString UCallbackPayload::GetIdentifier() const { return Identifier; }

FString UCallbackPayload::GetValue() const { return Value; }