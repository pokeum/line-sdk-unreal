#include "LineSDK/Tests/TestUtils.h"
#include "Misc/AutomationTest.h"
#include "Model/LoginResult.h"

DEFINE_SPEC(LoginResultTest, "Tests.Model.LoginResultTest",
            EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

void LoginResultTest::Define()
{
	const FString Json = TestUtils::GetStringFromFile("LoginResult.json");
	ULoginResult* LoginResult = ULoginResult::FromJson(Json);

	Describe(TEXT("Check AccessToken"), [this, LoginResult]()
	{
		auto What = TEXT("Check AccessToken");
		It(What, [this, What, LoginResult]()
		{
			TestEqual(What, LoginResult->GetAccessToken()->GetValue(), TEXT("abc123"));
		});

		What = TEXT("Check ExpiresIn");
		It(What, [this, What, LoginResult]()
		{
			TestEqual(What, LoginResult->GetAccessToken()->GetExpiresIn(), 12345l);
		});

		What = TEXT("Check IdToken");
		It(What, [this, What, LoginResult]()
		{
			TestEqual(What, LoginResult->GetAccessToken()->GetIdTokenRaw(), TEXT("abcdefg"));
		});

		What = TEXT("Check RefreshToken");
		It(What, [this, What, LoginResult]()
		{
			TestEqual(What, LoginResult->GetAccessToken()->GetRefreshToken(), TEXT("abc321"));
		});

		What = TEXT("Check Scope");
		It(What, [this, What, LoginResult]()
		{
			TestEqual(What, LoginResult->GetAccessToken()->GetScope(), TEXT("profile openid"));
		});

		What = TEXT("Check TokenType");
		It(What, [this, What, LoginResult]()
		{
			TestEqual(What, LoginResult->GetAccessToken()->GetTokenType(), TEXT("Bearer"));
		});
	});

	Describe(TEXT("Check UserProfile"), [this, LoginResult]()
	{
		auto What = TEXT("Check UserId");
		It(What, [this, What, LoginResult]()
		{
			TestEqual(What, LoginResult->GetUserProfile()->GetUserId(), TEXT("user_id"));
		});

		What = TEXT("Check DisplayName");
		It(What, [this, What, LoginResult]()
		{
			TestEqual(What, LoginResult->GetUserProfile()->GetDisplayName(), TEXT("testuser"));
		});

		What = TEXT("Check PictureUrl");
		It(What, [this, What, LoginResult]()
		{
			TestEqual(What, LoginResult->GetUserProfile()->GetPictureUrl(), TEXT("https://example.com/abcd"));
		});

		What = TEXT("Check StatusMessage");
		It(What, [this, What, LoginResult]()
		{
			TestEqual(What, LoginResult->GetUserProfile()->GetStatusMessage(), TEXT("Hi"));
		});
	});

	Describe(TEXT("Check"), [this, LoginResult]()
	{
		auto What = TEXT("Check Scope");
		It(What, [this, What, LoginResult]()
		{
			TestEqual(What, LoginResult->GetScopes().Num(), 2);
			TestTrue(What, LoginResult->GetScopes().Contains(TEXT("profile")));
			TestTrue(What, LoginResult->GetScopes().Contains(TEXT("openid")));
		});

		What = TEXT("Check FriendshipStatusChanged");
		It(What, [this, What, LoginResult]()
		{
			TestTrue(What, LoginResult->IsFriendshipStatusChanged());
		});

		What = TEXT("Check IDTokenNonce");
		It(What, [this, What, LoginResult]()
		{
			TestEqual(What, LoginResult->GetIdTokenNonce(), TEXT("ABCD"));
		});
	});
}
