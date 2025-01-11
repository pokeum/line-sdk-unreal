#include "Misc/AutomationTest.h"

#include "../Private/API/LineAPI.h"
#include "Model/UserProfile.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(APITestGetProfileOk, "Tests.API.APITestGetProfileOk",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

/**
 * Make the test pass by returning true,
 * or fail by returning false.
 */
bool APITestGetProfileOk::RunTest(const FString& Parameters)
{
	// Test result to return
	bool TestResult = true;
	// Test description
	auto What = TEXT("API Test Get Profile Ok");

	const auto Json = R"({
	"displayName": "testuser",
	"userId": "user_id",
	"pictureUrl": "https://example.com/abcd",
	"statusMessage": "Hi"
})";

	bool Called = false;

	FLineAPI::AddAction(UFlattenAction::JsonFlatten(UUserProfile::StaticClass(), [&](const UResult* Result)
	{
		What = TEXT("Result is success");
		if (!TestTrue(What, Result->IsSuccess()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]"), What);
			TestResult = false;
		}

		Result->MatchOk([&](const UResponse* Response)
		{
			const UUserProfile* UserProfile = Cast<UUserProfile>(Response);
			if (UserProfile)
			{
				Called = true;

				What = TEXT("Check UserId");
				if (!TestEqual(What, UserProfile->GetUserId(), TEXT("user_id")))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *UserProfile->GetUserId());
					TestResult = false;
				}

				What = TEXT("Check DisplayName");
				if (!TestEqual(What, UserProfile->GetDisplayName(), TEXT("testuser")))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *UserProfile->GetDisplayName());
					TestResult = false;
				}

				What = TEXT("Check StatusMessage");
				if (!TestEqual(What, UserProfile->GetStatusMessage(), TEXT("Hi")))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *UserProfile->GetStatusMessage());
					TestResult = false;
				}

				What = TEXT("Check PictureUrl");
				if (!TestEqual(What, UserProfile->GetPictureUrl(), TEXT("https://example.com/abcd")))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *UserProfile->GetPictureUrl());
					TestResult = false;
				}

				What = TEXT("Check PictureUrl - Large");
				if (!TestEqual(What, UserProfile->GetPictureUrlLarge(), TEXT("https://example.com/abcd/large")))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *UserProfile->GetPictureUrlLarge());
					TestResult = false;
				}

				What = TEXT("Check PictureUrl - Small");
				if (!TestEqual(What, UserProfile->GetPictureUrlSmall(), TEXT("https://example.com/abcd/small")))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]: Actual={%s}"), What, *UserProfile->GetPictureUrlSmall());
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