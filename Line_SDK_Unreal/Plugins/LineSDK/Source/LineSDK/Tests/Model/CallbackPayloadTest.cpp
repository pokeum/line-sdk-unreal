#include "Misc/AutomationTest.h"
#include "Model/CallbackPayload.h"

DEFINE_SPEC(CallbackPayloadTest, "Tests.Model.CallbackPayloadTest",
            EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

void CallbackPayloadTest::Define()
{
	// Test description
	auto What = TEXT("Callback Payload Test");

	What = TEXT("Test Parse");
	Describe(What, [this, &What]()
	{
		const auto Json = R"({
	"identifier": "4c53e374-fa5f-493c-8d17-e585204ee3ee",
	"value": "{\"code\":1,\"message\":\"login is canceled\"}"
})";

		UCallbackPayload* Payload = UCallbackPayload::FromJson(Json);

		What = TEXT("Check Identifier");
		It(What, [this, What, Payload]()
		{
			TestEqual(What, Payload->GetIdentifier(), TEXT("4c53e374-fa5f-493c-8d17-e585204ee3ee"));
		});

		What = TEXT("Check Value");
		It(What, [this, What, Payload]()
		{
			TestEqual(What, Payload->GetValue(), TEXT("{\"code\":1,\"message\":\"login is canceled\"}"));
		});
	});

	What = TEXT("Test Wrap");
	Describe(What, [this, &What]()
	{
		const FString Json = UCallbackPayload::WrapValue(TEXT("test_identifier"), TEXT("test_value"));
		UCallbackPayload* Payload = UCallbackPayload::FromJson(Json);

		What = TEXT("Check Identifier");
		It(What, [this, What, Payload]()
		{
			TestEqual(What, Payload->GetIdentifier(), TEXT("test_identifier"));
		});

		What = TEXT("Check Value");
		It(What, [this, What, Payload]()
		{
			TestEqual(What, Payload->GetValue(), TEXT("test_value"));
		});
	});
}