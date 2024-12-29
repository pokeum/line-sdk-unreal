#include "Misc/AutomationTest.h"

#include "../Private/API/LineAPI.h"
#include "Model/AccessTokenVerifyResult.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(APITestVerifyAccessTokenOk, "Tests.API.APITestVerifyAccessTokenOk",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

/**
 * Make the test pass by returning true,
 * or fail by returning false.
 */
bool APITestVerifyAccessTokenOk::RunTest(const FString& Parameters)
{
	// Test result to return
	bool TestResult = true;
	// Test description
	auto What = TEXT("API Test Verify Access Token Ok");

	const auto Json = R"({
	"client_id": "12345678",
	"expires_in": 12345,
	"scope": "profile openid"
})";

	bool Called = false;

	FLineAPI::AddAction(UFlattenAction::JsonFlatten(UAccessTokenVerifyResult::StaticClass(), [&](const UResult* Result)
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

			const UAccessTokenVerifyResult* AccessTokenVerifyResult = Cast<UAccessTokenVerifyResult>(Response);
			if (AccessTokenVerifyResult)
			{
				What = TEXT("Check ClientId");
				if (!TestEqual(What, AccessTokenVerifyResult->GetChannelId(), TEXT("12345678")))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *AccessTokenVerifyResult->GetChannelId());
					TestResult = false;
				}

				What = TEXT("Check Scope");
				if (!TestEqual(What, AccessTokenVerifyResult->GetScope(), TEXT("profile openid")))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *AccessTokenVerifyResult->GetScope());
					TestResult = false;
				}

				What = TEXT("Check ExpiresIn");
				if (!TestEqual(What, AccessTokenVerifyResult->GetExpiresIn(), 12345l))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%lld}"), What, AccessTokenVerifyResult->GetExpiresIn());
					TestResult = false;
				}
			}
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
