#include "Line_SDK_Unreal/Public/Widgets/MainWidget.h"

#include "LineSDK.h"
#include "Components/Button.h"

void UMainWidget::NativeConstruct()
{
	Super::NativeConstruct();
	this->InitUI();
}

void UMainWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void UMainWidget::OnClickButtonLogin()
{
	FLineSDK::Login(
		TArray<FString>(),
		[](const UResult* Result)
		{
			Result->Match(
				[](const UResponse* Response)
				{
					const ULoginResult* LoginResult = Cast<ULoginResult>(Response);
					if (LoginResult)
					{
						FLineSDK::Logger(FString::Printf(TEXT("[Login][Ok] %s"), *LoginResult->ToJson()));	
					}
				},
				[](const UError* Error)
				{
					FLineSDK::Logger(FString::Printf(TEXT("[Login][Error] %s"), *Error->ToJson()));
				}
			);
		}
	);
}

void UMainWidget::OnClickButtonGetProfile()
{
	FLineSDK::GetProfile([](const UResult* Result)
	{
		Result->Match(
			[](const UResponse* Response)
			{
				const UUserProfile* UserProfile = Cast<UUserProfile>(Response);
				if (UserProfile)
				{
					FLineSDK::Logger(FString::Printf(TEXT("[Get Profile][Ok] %s"), *UserProfile->ToJson()));
				}
			},
			[](const UError* Error)
			{
				FLineSDK::Logger(FString::Printf(TEXT("[Get Profile][Error] %s"), *Error->ToJson()));
			}
		);
	});
}

void UMainWidget::OnClickButtonGetCurrentAccessToken()
{
	const FString AccessToken = FLineSDK::GetCurrentAccessToken();
	FLineSDK::Logger(FString::Printf(TEXT("[Get Current Access Token] %s"), *AccessToken));
}

void UMainWidget::OnClickButtonLogout()
{
	FLineSDK::Logout([](const UResult* Result)
	{
		Result->Match(
			[](const UResponse* _)
			{
				FLineSDK::Logger(TEXT("[Logout][Ok]"));
			},
			[](const UError* Error)
			{
				FLineSDK::Logger(FString::Printf(TEXT("[Logout][Error] %s"), *Error->ToJson()));
			}
		);
	});
}

void UMainWidget::OnClickButtonGetBotFriendshipStatus()
{
	FLineSDK::GetBotFriendshipStatus([](const UResult* Result)
	{
		Result->Match(
			[](const UResponse* Response)
			{
				const UBotFriendshipStatus* BotFriendshipStatus = Cast<UBotFriendshipStatus>(Response);
				if (BotFriendshipStatus)
				{
					FLineSDK::Logger(FString::Printf(TEXT("[Get Bot Friendship Status][Ok] %s"), *BotFriendshipStatus->ToJson()));	
				}
			},
			[](const UError* Error)
			{
				FLineSDK::Logger(FString::Printf(TEXT("[Get Bot Friendship Status][Error] %s"), *Error->ToJson()));
			}
		);
	});
}

void UMainWidget::OnClickButtonRefreshAccessToken()
{
	FLineSDK::RefreshAccessToken([](const UResult* Result)
	{
		Result->Match(
			[](const UResponse* Response)
			{
				const UAccessToken* AccessToken = Cast<UAccessToken>(Response);
				if (AccessToken)
				{
					FLineSDK::Logger(FString::Printf(TEXT("[Refresh Access Token][Ok] %s"), *AccessToken->ToJson()));	
				}
			},
			[](const UError* Error)
			{
				FLineSDK::Logger(FString::Printf(TEXT("[Refresh Access Token][Error] %s"), *Error->ToJson()));
			}
		);
	});
}

void UMainWidget::OnClickButtonRevokeAccessToken()
{
	FLineSDK::RevokeAccessToken([](const UResult* Result)
	{
		Result->Match(
			[](const UResponse* _)
			{
				FLineSDK::Logger(TEXT("[Revoke Access Token][Ok]"));
			},
			[](const UError* Error)
			{
				FLineSDK::Logger(FString::Printf(TEXT("[Revoke Access Token][Error] %s"), *Error->ToJson()));
			}
		);
	});
}

void UMainWidget::OnClickButtonVerifyAccessToken()
{
	FLineSDK::VerifyAccessToken([](const UResult* Result)
	{
		Result->Match(
			[](const UResponse* Response)
			{
				const UAccessTokenVerifyResult* AccessTokenVerifyResult = Cast<UAccessTokenVerifyResult>(Response);
				if (AccessTokenVerifyResult)
				{
					FLineSDK::Logger(FString::Printf(TEXT("[Verify Access Token][Error] %s"), *AccessTokenVerifyResult->ToJson()));	
				}
			},
			[](const UError* Error)
			{
				FLineSDK::Logger(FString::Printf(TEXT("[Verify Access Token][Error] %s"), *Error->ToJson()));
			}
		);
	});
}

void UMainWidget::InitUI()
{
	if (!ButtonLogin->OnClicked.IsBound())
		ButtonLogin->OnClicked.AddDynamic(this, &UMainWidget::OnClickButtonLogin);

	if (!ButtonGetProfile->OnClicked.IsBound())
		ButtonGetProfile->OnClicked.AddDynamic(this, &UMainWidget::OnClickButtonGetProfile);

	if (!ButtonGetCurrentAccessToken->OnClicked.IsBound())
		ButtonGetCurrentAccessToken->OnClicked.AddDynamic(this, &UMainWidget::OnClickButtonGetCurrentAccessToken);

	if (!ButtonLogout->OnClicked.IsBound())
		ButtonLogout->OnClicked.AddDynamic(this, &UMainWidget::OnClickButtonLogout);

	if (!ButtonGetBotFriendshipStatus->OnClicked.IsBound())
		ButtonGetBotFriendshipStatus->OnClicked.AddDynamic(this, &UMainWidget::OnClickButtonGetBotFriendshipStatus);

	if (!ButtonRefreshAccessToken->OnClicked.IsBound())
		ButtonRefreshAccessToken->OnClicked.AddDynamic(this, &UMainWidget::OnClickButtonRefreshAccessToken);

	if (!ButtonRevokeAccessToken->OnClicked.IsBound())
		ButtonRevokeAccessToken->OnClicked.AddDynamic(this, &UMainWidget::OnClickButtonRevokeAccessToken);

	if (!ButtonVerifyAccessToken->OnClicked.IsBound())
		ButtonVerifyAccessToken->OnClicked.AddDynamic(this, &UMainWidget::OnClickButtonVerifyAccessToken);
}
