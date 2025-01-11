#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Model/LoginOption.h"
#include "Model/StoredAccessToken.h"
#include "LineSDKBlueprint.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FLineSDKResultListener, const UResult*, Result);

/** @cond HIDDEN_SYMBOLS */
UCLASS()
class ULineSDKBlueprint : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Line|Line SDK")
	static void Logger(const FString& Message);

	UFUNCTION(BlueprintCallable, Category = "Line|Line SDK")
	static void Login(const TArray<FString>& Scopes, FLineSDKResultListener ResultListener);

	UFUNCTION(BlueprintCallable, Category = "Line|Line SDK")
	static void LoginWithOption(const TArray<FString>& Scopes, const ULoginOption* Option, FLineSDKResultListener ResultListener);
	
	UFUNCTION(BlueprintCallable, Category = "Line|Line SDK")
	static void Logout(FLineSDKResultListener ResultListener);

	UFUNCTION(BlueprintCallable, Category = "Line|Line SDK")
	static void RefreshAccessToken(FLineSDKResultListener ResultListener);

	UFUNCTION(BlueprintCallable, Category = "Line|Line SDK")
	static void RevokeAccessToken(FLineSDKResultListener ResultListener);

	UFUNCTION(BlueprintCallable, Category = "Line|Line SDK")
	static void VerifyAccessToken(FLineSDKResultListener ResultListener);

	UFUNCTION(BlueprintCallable, Category = "Line|Line SDK")
	static void GetProfile(FLineSDKResultListener ResultListener);

	UFUNCTION(BlueprintCallable, Category = "Line|Line SDK")
	static void GetBotFriendshipStatus(FLineSDKResultListener ResultListener);

	UFUNCTION(BlueprintCallable, Category = "Line|Line SDK")
	static UPARAM(DisplayName = "Stored Access Token") UStoredAccessToken* GetCurrentAccessToken();
};
/** @endcond */