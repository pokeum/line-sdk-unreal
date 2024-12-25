#include "Utils/UserInterfaceUtils.h"

void UserInterfaceUtils::FromGameThread(const TFunction<void()>& Function)
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