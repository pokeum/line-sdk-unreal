#include "Model/CallbackPayload.h"

#include "Utils/LineSDKJsonKey.h"

UCallbackPayload* UCallbackPayload::FromJson(const FString& Json)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Json);
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		// Identifier
		if (!JsonObject->HasField(LineSDKJsonKey::CallbackPayload::Identifier)) return nullptr;
		FString	Identifier = JsonObject->GetStringField(LineSDKJsonKey::CallbackPayload::Identifier);

		// Value
		if (!JsonObject->HasField(LineSDKJsonKey::CallbackPayload::Value)) return nullptr;
		FString	Value = JsonObject->GetStringField(LineSDKJsonKey::CallbackPayload::Value);

		UCallbackPayload* Payload = NewObject<UCallbackPayload>(GetTransientPackage(), StaticClass());
		Payload->Identifier = Identifier;
		Payload->Value = Value;
		return Payload;
	}
	return nullptr;
}

UCallbackPayload::UCallbackPayload(const FString& Identifier, const FString& Value)
{
	this->Identifier = Identifier;
	this->Value = Value;
}
	
FString UCallbackPayload::ToJson() const
{
	return TEXT("");
}

FString UCallbackPayload::WrapValue(const FString& Identifier, const FString& Value)
{
	UCallbackPayload Payload(Identifier, Value);
	return Payload.ToJson();
}

FString UCallbackPayload::GetIdentifier() const { return Identifier; }
FString UCallbackPayload::GetValue() const { return Value; }