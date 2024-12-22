#pragma once

#include "CoreMinimal.h"
#include "UserProfile.generated.h"

UCLASS()
class LINESDK_API UUserProfile : public UObject
{
	GENERATED_BODY()

public:
	static UUserProfile* FromJson(const FString& Json);

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
	UFUNCTION(BlueprintCallable, Category = "Line SDK|User Profile")
	UPARAM(DisplayName = "User Id") FString GetUserId() const;

	UFUNCTION(BlueprintCallable, Category = "Line SDK|User Profile")
	UPARAM(DisplayName = "Display Name") FString GetDisplayName() const;

	UFUNCTION(BlueprintCallable, Category = "Line SDK|User Profile")
	UPARAM(DisplayName = "Picture Url") FString GetPictureUrl() const;

	UFUNCTION(BlueprintCallable, Category = "Line SDK|User Profile")
	UPARAM(DisplayName = "Status Message") FString GetStatusMessage() const;
};
