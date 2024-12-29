#include "Misc/AutomationTest.h"

#include "../Private/API/LineAPI.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(APITestRevokeTokenError, "Tests.API.APITestRevokeTokenError",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

/**
 * Make the test pass by returning true,
 * or fail by returning false.
 */
bool APITestRevokeTokenError::RunTest(const FString& Parameters)
{
	// Test result to return
	bool TestResult = true;
	// Test description
	auto What = TEXT("API Test Revoke Token Error");
	
	const auto Json = R"({
	"code": 123,
	"message": "error"
})";

	bool Called = false;

	FLineAPI::AddAction(UFlattenAction::JsonFlatten(UUnit::StaticClass(), [&](const UResult* Result)
	{
		What = TEXT("Result is failure");
		if (!TestTrue(What, Result->IsFailure()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]"), What);
			TestResult = false;
		}

		Result->MatchError([&](const UError* Error)
		{
			Called = true;

			What = TEXT("Check Code");
			if (!TestEqual(What, Error->GetCode(), 123))
			{
				UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%d}"), What, Error->GetCode());
				TestResult = false;
			}

			What = TEXT("Check Message");
			if (!TestEqual(What, Error->GetMessage(), TEXT("error")))
			{
				UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *Error->GetMessage());
				TestResult = false;
			}
		});
	}));
	
	const FString Identifier = FLineAPI::Actions.CreateConstIterator()->Key;
	FLineAPI::OnApiError(UCallbackPayload::WrapValue(Identifier, Json));

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
