#include "Utils/UserInterfaceUtils.h"

UUserInterfaceUtils::UUserInterfaceUtils(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UUserInterfaceUtils::FromGameThread(const TFunction<void()>& Function)
{
	// Unreal Slate can only be accessed from the GameThread or the SlateLoadingThread!
	if (IsInGameThread())
	{
		if (Function) Function();
	}
	else
	{
		// Ensure the code runs on the game thread
		AsyncTask(ENamedThreads::GameThread, [Function]()
		{
			if (Function) Function();
		});
	}
}

void UUserInterfaceUtils::RunFromGameThread(const FGameThreadRunner Runner)
{
	FromGameThread([Runner]()
	{
		if (Runner.IsBound()) { Runner.Execute(); }
	});
}