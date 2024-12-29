#include "Misc/AutomationTest.h"

#include "../Private/API/LineAPI.h"
#include "Model/AccessToken.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(APITestRefreshTokenOk, "Tests.API.APITestRefreshTokenOk",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

/**
 * Make the test pass by returning true,
 * or fail by returning false.
 */
bool APITestRefreshTokenOk::RunTest(const FString& Parameters)
{
	// Test result to return
	bool TestResult = true;
	// Test description
	auto What = TEXT("API Test Refresh Token Ok");

	const auto Json = R"({
	"access_token": "abc123",
	"expires_in": 12345,
	"id_token": "abcdefg",
	"refresh_token": "abc321",
	"scope":"profile openid",
	"token_type": "Bearer"
})";

	bool Called = false;

	FLineAPI::AddAction(UFlattenAction::JsonFlatten(UAccessToken::StaticClass(), [&](const UResult* Result)
	{
		What = TEXT("Result is success");
		if (!TestTrue(What, Result->IsSuccess()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]"), What);
			TestResult = false;
		}

		Result->MatchOk([&](const UResponse* Response)
		{
			const UAccessToken* AccessToken = Cast<UAccessToken>(Response);
			if (AccessToken)
			{
				Called = true;

				What = TEXT("Check AccessToken");
				if (!TestEqual(What, AccessToken->GetValue(), TEXT("abc123")))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetValue());
					TestResult = false;
				}

				What = TEXT("Check ExpiresIn");
				if (!TestEqual(What, AccessToken->GetExpiresIn(), 12345l))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%lld}"), What, AccessToken->GetExpiresIn());
					TestResult = false;
				}

				What = TEXT("Check IdToken");
				if (!TestEqual(What, AccessToken->GetIdTokenRaw(), TEXT("abcdefg")))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetIdTokenRaw());
					TestResult = false;
				}

				What = TEXT("Check RefreshToken");
				if (!TestEqual(What, AccessToken->GetRefreshToken(), TEXT("abc321")))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetRefreshToken());
					TestResult = false;
				}

				What = TEXT("Check Scope");
				if (!TestEqual(What, AccessToken->GetScope(), TEXT("profile openid")))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetScope());
					TestResult = false;
				}

				What = TEXT("Check TokenType");
				if (!TestEqual(What, AccessToken->GetTokenType(), TEXT("Bearer")))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetTokenType());
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
