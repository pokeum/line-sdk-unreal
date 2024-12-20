#include "LineSDK/Tests/Utils/TestUtils.h"
#include "Misc/AutomationTest.h"
#include "Model/CallbackPayload.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(CallbackPayloadTest, "Tests.Model.CallbackPayloadTest",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

/**
 * Make the test pass by returning true,
 * or fail by returning false.
 */
bool CallbackPayloadTest::RunTest(const FString& Parameters)
{
	// Login Canceled
	FString Json = TestUtils::GetStringFromFile("CallbackPayload_Login_Canceled.json");
	UCallbackPayload* Payload = UCallbackPayload::FromJson(Json);

	if (!TestEqual(TEXT("Check Identifier"),
	               Payload->GetIdentifier(),
	               TEXT("4c53e374-fa5f-493c-8d17-e585204ee3ee")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [Login Canceled][Check Identifier]: Actual={%s}"), *Payload->GetIdentifier());
		return false;
	}
	if (!TestEqual(TEXT("Check Value"),
	               Payload->GetValue(),
	               TEXT("{\"code\":1,\"message\":\"login is canceled\"}")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [Login Canceled][Check Value]: Actual={%s}"), *Payload->GetValue());
		return false;
	}

	return true;
}
