#include "Misc/AutomationTest.h"
#include "Model/AccessToken.h"

DEFINE_SPEC(AccessTokenTest, "Tests.Model.AccessTokenTest",
            EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

void AccessTokenTest::Define()
{
	// Test description
	auto What = TEXT("Access Token Test");

	What = TEXT("Test Parse");
	Describe(What, [this, &What]()
	{
		const auto Json = R"({
	"access_token": "abc123",
	"expires_in": 12345,
	"id_token": "abcdefg",
	"refresh_token": "abc321",
	"scope": "profile openid",
	"token_type": "Bearer"
})";

		UAccessToken* AccessToken = UAccessToken::FromJson(Json);

		What = TEXT("Check AccessToken");
		It(What, [this, What, AccessToken]()
		{
			TestEqual(What, AccessToken->GetValue(), TEXT("abc123"));
		});

		What = TEXT("Check ExpiresIn");
		It(What, [this, What, AccessToken]()
		{
			TestEqual(What, AccessToken->GetExpiresIn(), 12345l);
		});

		What = TEXT("Check IdToken");
		It(What, [this, What, AccessToken]()
		{
			TestEqual(What, AccessToken->GetIdTokenRaw(), TEXT("abcdefg"));
		});

		What = TEXT("Check RefreshToken");
		It(What, [this, What, AccessToken]()
		{
			TestEqual(What, AccessToken->GetRefreshToken(), TEXT("abc321"));
		});

		What = TEXT("Check Scope");
		It(What, [this, What, AccessToken]()
		{
			TestEqual(What, AccessToken->GetScope(), TEXT("profile openid"));
		});

		What = TEXT("Check TokenType");
		It(What, [this, What, AccessToken]()
		{
			TestEqual(What, AccessToken->GetTokenType(), TEXT("Bearer"));
		});
	});
	
	What = TEXT("Test Invalid");
	Describe(What, [this, &What]()
	{
		What = TEXT("\"\" String");
		It(What, [this, What]()
		{
			const UAccessToken* AccessToken = UAccessToken::FromJson("");
			TestNull(What, AccessToken);
		});

		What = TEXT("\"abc\" String");
		It(What, [this, What]()
		{
			const UAccessToken* AccessToken = UAccessToken::FromJson(TEXT("abc"));
			TestNull(What, AccessToken);
		});
	});
}