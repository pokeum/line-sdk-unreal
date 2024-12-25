#include "Line_SDK_Unreal/Public/Widgets/MainWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Utils/UserInterfaceUtils.h"
#include "WebBrowserWidget/Public/WebBrowser.h"

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
		[&](const UResult* Result)
		{
			Result->Match(
				[&](const UResponse* Response)
				{
					const ULoginResult* LoginResult = Cast<ULoginResult>(Response);
					if (LoginResult)
					{
						UpdateResponse(LoginResult->ToJson());
						UpdateProfile(LoginResult->GetUserProfile());
					}
				},
				[&](const UError* Error)
				{
					UpdateResponse(Error->ToJson());
				}
			);
		}
	);
}

void UMainWidget::OnClickButtonGetProfile()
{
	FLineSDK::GetProfile([&](const UResult* Result)
	{
		Result->Match(
			[&](const UResponse* Response)
			{
				const UUserProfile* UserProfile = Cast<UUserProfile>(Response);
				if (UserProfile)
				{
					UpdateProfile(UserProfile);
					UpdateResponse(UserProfile->ToJson());
				}
			},
			[&](const UError* Error)
			{
				UpdateResponse(Error->ToJson());
			}
		);
	});
}

void UMainWidget::OnClickButtonGetCurrentAccessToken()
{
	const UStoredAccessToken* StoredAccessToken = FLineSDK::GetCurrentAccessToken();
	if (StoredAccessToken)
	{
		UpdateResponse(StoredAccessToken->ToJson());	
	}
}

void UMainWidget::OnClickButtonLogout()
{
	FLineSDK::Logout([&](const UResult* Result)
	{
		Result->Match(
			[&](const UResponse* _)
			{
				ResetProfile();
			},
			[&](const UError* Error)
			{
				UpdateResponse(Error->ToJson());
			}
		);
	});
}

void UMainWidget::OnClickButtonGetBotFriendshipStatus()
{
	FLineSDK::GetBotFriendshipStatus([&](const UResult* Result)
	{
		Result->Match(
			[&](const UResponse* Response)
			{
				const UBotFriendshipStatus* BotFriendshipStatus = Cast<UBotFriendshipStatus>(Response);
				if (BotFriendshipStatus)
				{
					UpdateResponse(BotFriendshipStatus->ToJson());
				}
			},
			[&](const UError* Error)
			{
				UpdateResponse(Error->ToJson());
			}
		);
	});
}

void UMainWidget::OnClickButtonRefreshAccessToken()
{
	FLineSDK::RefreshAccessToken([&](const UResult* Result)
	{
		Result->Match(
			[&](const UResponse* Response)
			{
				const UAccessToken* AccessToken = Cast<UAccessToken>(Response);
				if (AccessToken)
				{
					UpdateResponse(AccessToken->ToJson());
				}
			},
			[&](const UError* Error)
			{
				UpdateResponse(Error->ToJson());
			}
		);
	});
}

void UMainWidget::OnClickButtonRevokeAccessToken()
{
	FLineSDK::RevokeAccessToken([&](const UResult* Result)
	{
		Result->Match(
			[&](const UUnit* _)
			{
			},
			[&](const UError* Error)
			{
				UpdateResponse(Error->ToJson());
			}
		);
	});
}

void UMainWidget::OnClickButtonVerifyAccessToken()
{
	FLineSDK::VerifyAccessToken([&](const UResult* Result)
	{
		Result->Match(
			[&](const UResponse* Response)
			{
				const UAccessTokenVerifyResult* AccessTokenVerifyResult = Cast<UAccessTokenVerifyResult>(Response);
				if (AccessTokenVerifyResult)
				{
					UpdateResponse(AccessTokenVerifyResult->ToJson());
				}
			},
			[&](const UError* Error)
			{
				UpdateResponse(Error->ToJson());
			}
		);
	});
}

void UMainWidget::InitUI()
{
	WebBrowser->SetVisibility(ESlateVisibility::Hidden);
	
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

void UMainWidget::UpdateProfile(const UUserProfile* Profile)
{
	UserInterfaceUtils::FromGameThread([&, Profile]()
	{
		WebBrowser->SetVisibility(ESlateVisibility::Visible);
		WebBrowser->LoadURL(Profile->GetPictureUrl());

		TextDisplayName->SetText(FText::FromString(Profile->GetDisplayName()));
		TextStatusMessage->SetText(FText::FromString(Profile->GetStatusMessage()));
	});
}

void UMainWidget::ResetProfile()
{
	UserInterfaceUtils::FromGameThread([&]()
	{
		WebBrowser->SetVisibility(ESlateVisibility::Hidden);

		TextDisplayName->SetText(FText::FromString(TEXT("Display Name")));
		TextStatusMessage->SetText(FText::FromString(TEXT("Status Message")));
	});
}

void UMainWidget::UpdateResponse(const FString& Response)
{
	UserInterfaceUtils::FromGameThread([&, Response]()
	{
		TextResponse->SetText(FText::FromString(Response));
	});
}
