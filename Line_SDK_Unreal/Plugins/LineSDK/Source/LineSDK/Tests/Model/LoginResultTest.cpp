#include "Misc/AutomationTest.h"
#include "Model/LoginResult.h"

DEFINE_SPEC(LoginResultTest, "Tests.Model.LoginResultTest",
            EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

void LoginResultTest::Define()
{
	// Test description
	auto What = TEXT("Login Result Test");
	
	const auto Json = R"({
	"accessToken": {
		"access_token": "abc123",
		"expires_in": 12345,
		"id_token": "abcdefg",
		"refresh_token": "abc321",
		"scope": "profile openid",
		"token_type": "Bearer"
	},
	"scope": "profile openid",
	"userProfile": {
		"displayName": "testuser",
		"userId": "user_id",
		"pictureUrl": "https://example.com/abcd",
		"statusMessage": "Hi"
	},
	"friendshipStatusChanged": true,
	"IDTokenNonce": "ABCD"
})";

	ULoginResult* LoginResult = ULoginResult::FromJson(Json);

	What = TEXT("Check AccessToken");
	Describe(What, [this, &What, LoginResult]()
	{
		What = TEXT("Check AccessToken");
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

	What = TEXT("Check UserProfile");
	Describe(What, [this, &What, LoginResult]()
	{
		What = TEXT("Check UserId");
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

	What = TEXT("Check");
	Describe(What, [this, &What, LoginResult]()
	{
		What = TEXT("Check Scope");
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