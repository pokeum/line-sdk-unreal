#include "LineSDK/Tests/TestUtils.h"
#include "Misc/AutomationTest.h"
#include "Model/LoginResult.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(LoginResultTest, "Tests.Model.LoginResultTest",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

#define TEST_FROM_JSON	TEXT("FromJson()")

/**
 * Make the test pass by returning true,
 * or fail by returning false.
 */
bool LoginResultTest::RunTest(const FString& Parameters)
{
	auto What = TEXT("");

#pragma region TEST_FROM_JSON

	LINE_SDK_TEST_LOG(TEXT("Test: %s"), TEST_FROM_JSON);
	FString Json = TestUtils::GetStringFromFile("LoginResult_Dummy.json");
	ULoginResult* LoginResult = ULoginResult::FromJson(Json);

#pragma region ACCESS_TOKEN
	
	What = TEXT("Check AccessToken:AccessToken");
	if (!TestEqual(What, LoginResult->GetAccessToken()->GetAccessToken(), TEXT("abc123")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"),
		                  TEST_FROM_JSON, What, *LoginResult->GetAccessToken()->GetAccessToken());
		return false;
	}
	
	What = TEXT("Check AccessToken:ExpiresIn");
	if (!TestEqual(What, LoginResult->GetAccessToken()->GetExpiresIn(), static_cast<int64>(12345)))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%lld}"),
		                  TEST_FROM_JSON, What, LoginResult->GetAccessToken()->GetExpiresIn());
		return false;
	}
	
	What = TEXT("Check AccessToken:IdToken");
	if (!TestEqual(What, LoginResult->GetAccessToken()->GetIdToken(), TEXT("abcdefg")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"),
		                  TEST_FROM_JSON, What, *LoginResult->GetAccessToken()->GetIdToken());
		return false;
	}
	
	What = TEXT("Check AccessToken:RefreshToken");
	if (!TestEqual(What, LoginResult->GetAccessToken()->GetRefreshToken(), TEXT("abc321")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"),
		                  TEST_FROM_JSON, What, *LoginResult->GetAccessToken()->GetRefreshToken());
		return false;
	}
	
	What = TEXT("Check AccessToken:Scope");
	if (!TestEqual(What, LoginResult->GetAccessToken()->GetScope(), TEXT("profile openid")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"),
		                  TEST_FROM_JSON, What, *LoginResult->GetAccessToken()->GetScope());
		return false;
	}
	
	What = TEXT("Check AccessToken:TokenType");
	if (!TestEqual(What, LoginResult->GetAccessToken()->GetTokenType(), TEXT("Bearer")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"),
		                  TEST_FROM_JSON, What, *LoginResult->GetAccessToken()->GetTokenType());
		return false;
	}

#pragma endregion

	What = TEXT("Check Scope");
	if (!TestEqual(What, LoginResult->GetScope(), TEXT("profile openid")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"), TEST_FROM_JSON, What, *LoginResult->GetScope());
		return false;
	}

#pragma region USER_PROFILE

	What = TEXT("Check UserProfile:UserId");
	if (!TestEqual(What, LoginResult->GetUserProfile()->GetUserId(), TEXT("user_id")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"),
						  TEST_FROM_JSON, What, *LoginResult->GetUserProfile()->GetUserId());
		return false;
	}
	
	What = TEXT("Check UserProfile:DisplayName");
	if (!TestEqual(What, LoginResult->GetUserProfile()->GetDisplayName(), TEXT("testuser")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"),
						  TEST_FROM_JSON, What, *LoginResult->GetUserProfile()->GetDisplayName());
		return false;
	}

	What = TEXT("Check UserProfile:PictureUrl");
	if (!TestEqual(What, LoginResult->GetUserProfile()->GetPictureUrl(), TEXT("https://example.com/abcd")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"),
						  TEST_FROM_JSON, What, *LoginResult->GetUserProfile()->GetPictureUrl());
		return false;
	}

	What = TEXT("Check UserProfile:StatusMessage");
	if (!TestEqual(What, LoginResult->GetUserProfile()->GetStatusMessage(), TEXT("Hi")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"),
						  TEST_FROM_JSON, What, *LoginResult->GetUserProfile()->GetStatusMessage());
		return false;
	}
	
#pragma endregion
	
	What = TEXT("Check FriendshipStatusChanged");
	if (!TestTrue(What, LoginResult->GetFriendshipStatusChanged()))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"), TEST_FROM_JSON, What,
			(LoginResult->GetFriendshipStatusChanged() ? TEXT("true") : TEXT("false")));
		return false;
	}

	What = TEXT("Check IDTokenNonce");
	if (!TestEqual(What, LoginResult->GetIDTokenNonce(), TEXT("ABCD")))
	{
		LINE_SDK_TEST_LOG(TEXT("Fail: [%s][%s]: Actual={%s}"), TEST_FROM_JSON, What, *LoginResult->GetIDTokenNonce());
		return false;
	}

#pragma endregion

	return true;
}
