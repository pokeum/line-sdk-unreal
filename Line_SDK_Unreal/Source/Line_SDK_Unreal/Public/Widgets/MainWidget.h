#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LineSDK.h"
#include "MainWidget.generated.h"

class UButton;
class UTextBlock;

UCLASS()
class LINE_SDK_UNREAL_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
protected:
	 UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	 class UWebBrowser* WebBrowser;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextDisplayName;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextStatusMessage;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextResponse;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonLogin;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonGetProfile;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonGetCurrentAccessToken;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonLogout;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonGetBotFriendshipStatus;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonRefreshAccessToken;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonRevokeAccessToken;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonVerifyAccessToken;
	
	UFUNCTION()
	void OnClickButtonLogin();
	
	UFUNCTION()
	void OnClickButtonGetProfile();
	
	UFUNCTION()
	void OnClickButtonGetCurrentAccessToken();
	
	UFUNCTION() 
	void OnClickButtonLogout();
	
	UFUNCTION()
	void OnClickButtonGetBotFriendshipStatus();
	
	UFUNCTION()
	void OnClickButtonRefreshAccessToken();
	
	UFUNCTION()
	void OnClickButtonRevokeAccessToken();
	
	UFUNCTION()
	void OnClickButtonVerifyAccessToken();


private:
	void InitUI();
	
	void UpdateProfile(const UUserProfile* Profile);

	void ResetProfile();
	
	void UpdateResponse(const FString& Response);
};
