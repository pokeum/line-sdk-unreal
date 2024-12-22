#include "JSONUtils.h"

namespace JSONUtils
{
	bool GetStringField(const TSharedPtr<FJsonObject>& JsonObject, const FString& FieldName, FString& Field, const FString& Default)
	{
		if (JsonObject.IsValid() && JsonObject->HasField(FieldName))
		{
			Field = JsonObject->GetStringField(FieldName);
			return true;
		}
		Field = Default;
		return false;
	}

	bool GetInt32Field(const TSharedPtr<FJsonObject>& JsonObject, const FString& FieldName, int32& Field, const int32& Default)
	{
		if (JsonObject.IsValid() && JsonObject->HasField(FieldName))
		{
			Field = JsonObject->GetIntegerField(FieldName);
			return true;
		}
		Field = Default;
		return false;
	}

	bool GetInt64Field(const TSharedPtr<FJsonObject>& JsonObject, const FString& FieldName, int64& Field, const int64& Default)
	{
		if (JsonObject.IsValid() && JsonObject->HasField(FieldName))
		{
			Field = static_cast<int64>(JsonObject->GetNumberField(FieldName));
			return true;
		}
		Field = Default;
		return false;
	}

	bool GetBoolField(const TSharedPtr<FJsonObject>& JsonObject, const FString& FieldName, bool& Field, const bool& Default)
	{
		if (JsonObject.IsValid() && JsonObject->HasField(FieldName))
		{
			Field = JsonObject->GetBoolField(FieldName);
			return true;
		}
		Field = Default;
		return false;
	}

	bool GetObjectField(const TSharedPtr<FJsonObject>& JsonObject, const FString& FieldName, FString& Field, const FString& Default)
	{
		if (JsonObject.IsValid() && JsonObject->HasField(FieldName))
		{
			const TSharedPtr<FJsonObject> Object = JsonObject->GetObjectField(FieldName);
			if (Object.IsValid())
			{
				FString JsonString;
				const TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
				
				if (FJsonSerializer::Serialize(Object.ToSharedRef(), Writer))
				{
					Field = JsonString;
					return true;
				}
			}
		}
		Field = Default;
		return false;
	}

	/** JsonObject to Json String */
	FString ToJson(const TSharedPtr<FJsonObject>& JsonObject)
	{
		FString JsonString;
		const TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
		if (FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer))
		{
			return JsonString;
		}
		return TEXT("");
	}
}
