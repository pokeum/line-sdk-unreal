#include "Misc/AutomationTest.h"
#include "Model/AccessToken.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(EmptyAccessTokenTest, "Tests.Model.EmptyAccessTokenTest",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

/**
 * Make the test pass by returning true,
 * or fail by returning false.
 */
bool EmptyAccessTokenTest::RunTest(const FString& Parameters)
{
	// Test description
	auto What = TEXT("Empty Access Token Test");

	const UAccessToken* AccessToken = UAccessToken::FromJson(TEXT("{}"));

	What = TEXT("Check Not Null");
	if (!TestNotNull(What, AccessToken))
	{
		return false;
	}

	What = TEXT("Check AccessToken");
	if (!TestEqual(What, AccessToken->GetValue(), TEXT("")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetValue());
		return false;
	}

	What = TEXT("Check ExpiresIn");
	if (!TestEqual(What, AccessToken->GetExpiresIn(), 0l))
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%lld}"), What, AccessToken->GetExpiresIn());
		return false;
	}

	What = TEXT("Check IdToken");
	if (!TestEqual(What, AccessToken->GetIdTokenRaw(), TEXT("")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetIdTokenRaw());
		return false;
	}

	What = TEXT("Check RefreshToken");
	if (!TestEqual(What, AccessToken->GetRefreshToken(), TEXT("")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetRefreshToken());
		return false;
	}

	What = TEXT("Check Scope");
	if (!TestEqual(What, AccessToken->GetScope(), TEXT("")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetScope());
		return false;
	}

	What = TEXT("Check TokenType");
	if (!TestEqual(What, AccessToken->GetTokenType(), TEXT("")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetTokenType());
		return false;
	}

	return true;
}
