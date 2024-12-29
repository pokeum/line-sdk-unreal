#include "Misc/AutomationTest.h"

#include "../Private/API/LineAPI.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(APITestRevokeTokenOk, "Tests.API.APITestRevokeTokenOk",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

/**
 * Make the test pass by returning true,
 * or fail by returning false.
 */
bool APITestRevokeTokenOk::RunTest(const FString& Parameters)
{
	// Test result to return
	bool TestResult = true;
	// Test description
	auto What = TEXT("API Test Revoke Token Ok");

	const auto Json = TEXT("{}");

	bool Called = false;

	FLineAPI::AddAction(UFlattenAction::JsonFlatten(UUnit::StaticClass(), [&](const UResult* Result)
	{
		What = TEXT("Result is success");
		if (!TestTrue(What, Result->IsSuccess()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]"), What);
			TestResult = false;
		}

		Result->MatchOk([&](const UResponse* Response)
		{
			Called = true;
		});
	}));

	const FString Identifier = FLineAPI::Actions.CreateConstIterator()->Key;
	FLineAPI::OnApiOk(UCallbackPayload::WrapValue(Identifier, Json));

	What = TEXT("Callback is called");
	if (!TestTrue(What, Called))
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]"), What);
		TestResult = false;
	}

	What = TEXT("Action is empty");
	if (!TestEqual("Action is empty", FLineAPI::Actions.Num(), 0))
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%d}"), What, FLineAPI::Actions.Num());
		TestResult = false;
	}

	return TestResult;
}