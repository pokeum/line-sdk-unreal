#include "LineSDK/Tests/TestUtils.h"
#include "Misc/AutomationTest.h"
#include "Model/AccessToken.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(AccessTokenTest, "Tests.Model.AccessTokenTest",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

#define TEST_FROM_JSON	TEXT("FromJson()")

/**
 * Make the test pass by returning true,
 * or fail by returning false.
 */
bool AccessTokenTest::RunTest(const FString& Parameters)
{
	auto What = TEXT("");

#pragma region TEST_FROM_JSON
	
	LINE_SDK_TEST_LOG(TEXT("Test: %s"), TEST_FROM_JSON);
	FString Json = TestUtils::GetStringFromFile("AccessToken_Refresh.json");
	UAccessToken* AccessToken = UAccessToken::FromJson(Json);

	What = TEXT("Check AccessToken");
	if (!TestEqual(What,
		AccessToken->GetAccessToken(),
		TEXT("eyJhbGciOiJIUzI1NiJ9.1pwlR1VSUoSP11ikunPXN5G07eWPvP9Tt7gzbDEUogCOH_SAHimN2ng_BT_mq98U6C9gQM7HeFWmTIU3fs4flTNBvlvtw-5kcu4ffqbobvM2kkgFswpZnpMfNXLuoezCKdn9XVAfwiGG-KnQbx6G6XPCG72yCKgHKOWl1f2j9Mk.CwjQOWaC3qFtE3IzHWsEg0q9mXgT3OZZLQV5qc3lsT0")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"), TEST_FROM_JSON, What, *AccessToken->GetAccessToken());
		return false;
	}
	
	What = TEXT("Check ExpiresIn");
	if (!TestEqual(What, AccessToken->GetExpiresIn(), 2592000000))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%lld}"), TEST_FROM_JSON, What, AccessToken->GetExpiresIn());
		return false;
	}
	
	What = TEXT("Check IdToken");
	if (!TestEqual(What, AccessToken->GetIdToken(), TEXT("")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"), TEST_FROM_JSON, What, *AccessToken->GetIdToken());
		return false;
	}
	
	What = TEXT("Check RefreshToken");
	if (!TestEqual(What, AccessToken->GetRefreshToken(), TEXT("")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"), TEST_FROM_JSON, What, *AccessToken->GetRefreshToken());
		return false;
	}

	What = TEXT("Check Scope");
	if (!TestEqual(What, AccessToken->GetScope(), TEXT("")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"), TEST_FROM_JSON, What, *AccessToken->GetScope());
		return false;
	}

	What = TEXT("Check TokenType");
	if (!TestEqual(What, AccessToken->GetTokenType(), TEXT("")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"), TEST_FROM_JSON, What, *AccessToken->GetTokenType());
		return false;
	}

#pragma endregion
	
	return true;
}
