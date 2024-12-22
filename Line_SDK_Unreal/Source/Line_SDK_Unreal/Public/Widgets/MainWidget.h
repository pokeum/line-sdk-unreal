#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

class UButton;

UCLASS()
class LINE_SDK_UNREAL_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
protected:
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

	void InitUI();
};
