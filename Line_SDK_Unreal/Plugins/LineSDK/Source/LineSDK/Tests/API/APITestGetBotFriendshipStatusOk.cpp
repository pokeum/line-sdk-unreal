#include "Misc/AutomationTest.h"

#include "../Private/API/LineAPI.h"
#include "Model/BotFriendshipStatus.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(APITestGetBotFriendshipStatusOk, "Tests.API.APITestGetBotFriendshipStatusOk",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

/**
 * Make the test pass by returning true,
 * or fail by returning false.
 */
bool APITestGetBotFriendshipStatusOk::RunTest(const FString& Parameters)
{
	// Test result to return
	bool TestResult = true;
	// Test description
	auto What = TEXT("API Test Get Bot Friendship Status Ok");

	const auto Json = R"({ "friendFlag": true })";

	bool Called = false;

	FLineAPI::AddAction(UFlattenAction::JsonFlatten(UBotFriendshipStatus::StaticClass(), [&](const UResult* Result)
	{
		What = TEXT("Result is success");
		if (!TestTrue(What, Result->IsSuccess()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]"), What);
			TestResult = false;
		}

		Result->MatchOk([&](const UResponse* Response)
		{
			const UBotFriendshipStatus* BotFriendshipStatus = Cast<UBotFriendshipStatus>(Response);
			if (BotFriendshipStatus)
			{
				Called = true;

				What = TEXT("Check FriendFlag");
				if (!TestTrue(What, BotFriendshipStatus->IsFriend()))
				{
					UE_LOG(LogTemp, Warning, TEXT("Fail: [%s]"), What);
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