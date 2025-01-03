#pragma once

#include "CoreMinimal.h"
#include "Utils/Response.h"
#include "UserProfile.generated.h"

UCLASS()
class LINESDK_API UUserProfile : public UResponse
{
	GENERATED_BODY()

public:
	static UUserProfile* FromJson(const FString& Json);

	TSharedPtr<FJsonObject> ToJsonObject() const;

	UFUNCTION(BlueprintCallable, Category = "Line|User Profile")
	UPARAM(DisplayName = "Json") FString ToJson() const;

private:
	UPROPERTY()
	FString UserId;

	UPROPERTY()
	FString DisplayName;

	UPROPERTY()
	FString PictureUrl;

	UPROPERTY()
	FString StatusMessage;

public:
	UFUNCTION(BlueprintCallable, Category = "Line|User Profile")
	UPARAM(DisplayName = "User Id") FString GetUserId() const;

	UFUNCTION(BlueprintCallable, Category = "Line|User Profile")
	UPARAM(DisplayName = "Display Name") FString GetDisplayName() const;

	UFUNCTION(BlueprintCallable, Category = "Line|User Profile")
	UPARAM(DisplayName = "Picture Url") FString GetPictureUrl() const;

	UFUNCTION(BlueprintCallable, Category = "Line|User Profile")
	UPARAM(DisplayName = "Status Message") FString GetStatusMessage() const;
};
