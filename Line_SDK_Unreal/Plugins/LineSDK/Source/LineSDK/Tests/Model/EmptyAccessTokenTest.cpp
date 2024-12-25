#include "LineSDK/Tests/TestUtils.h"
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
	const UAccessToken* AccessToken = UAccessToken::FromJson(TEXT("{}"));

	auto What = TEXT("Check Not Null");
	if (!TestNotNull(What, AccessToken))
	{
		return false;
	}

	What = TEXT("Check AccessToken");
	if (!TestEqual(What, AccessToken->GetValue(), TEXT("")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetValue());
		return false;
	}

	What = TEXT("Check ExpiresIn");
	if (!TestEqual(What, AccessToken->GetExpiresIn(), 0l))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s]: Actual={%lld}"), What, AccessToken->GetExpiresIn());
		return false;
	}

	What = TEXT("Check IdToken");
	if (!TestEqual(What, AccessToken->GetIdTokenRaw(), TEXT("")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetIdTokenRaw());
		return false;
	}

	What = TEXT("Check RefreshToken");
	if (!TestEqual(What, AccessToken->GetRefreshToken(), TEXT("")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetRefreshToken());
		return false;
	}

	What = TEXT("Check Scope");
	if (!TestEqual(What, AccessToken->GetScope(), TEXT("")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetScope());
		return false;
	}

	What = TEXT("Check TokenType");
	if (!TestEqual(What, AccessToken->GetTokenType(), TEXT("")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s]: Actual={%s}"), What, *AccessToken->GetTokenType());
		return false;
	}

	return true;
}
