#include "LineSDK/Tests/TestUtils.h"
#include "Misc/AutomationTest.h"
#include "Model/CallbackPayload.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(CallbackPayloadTest, "Tests.Model.CallbackPayloadTest",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

#define TEST_FROM_JSON		TEXT("FromJson()")
#define TEST_WRAP_VALUE		TEXT("WrapValue()")

/**
 * Make the test pass by returning true,
 * or fail by returning false.
 */
bool CallbackPayloadTest::RunTest(const FString& Parameters)
{
	auto What = TEXT("");

#pragma region TEST_FROM_JSON
	
	FString Json = TestUtils::GetStringFromFile("CallbackPayload_Login_Canceled.json");
	UCallbackPayload* Payload = UCallbackPayload::FromJson(Json);

	What = TEXT("Check Identifier");
	if (!TestEqual(What, Payload->GetIdentifier(), TEXT("4c53e374-fa5f-493c-8d17-e585204ee3ee")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"), TEST_FROM_JSON, What, *Payload->GetIdentifier());
		return false;
	}

	What = TEXT("Check Value");
	if (!TestEqual(What, Payload->GetValue(), TEXT("{\"code\":1,\"message\":\"login is canceled\"}")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"), TEST_FROM_JSON, What, *Payload->GetValue());
		return false;
	}

#pragma endregion

#pragma region TEST_WRAP_VALUE
	
	Json = UCallbackPayload::WrapValue(TEXT("test_identifier"), TEXT("test_value"));
	Payload = UCallbackPayload::FromJson(Json);

	What = TEXT("Check Identifier");
	if (!TestEqual(What, Payload->GetIdentifier(), TEXT("test_identifier")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"), TEST_WRAP_VALUE, What, *Payload->GetIdentifier());
		return false;
	}

	What = TEXT("Check Value");
	if (!TestEqual(What, Payload->GetValue(), TEXT("test_value")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"), TEST_WRAP_VALUE, What, *Payload->GetValue());
		return false;
	}
	
#pragma endregion
	
	return true;
}
