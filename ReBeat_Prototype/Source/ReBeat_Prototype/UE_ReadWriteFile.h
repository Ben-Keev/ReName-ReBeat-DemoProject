#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "UE_ReadWriteFile.generated.h"

UCLASS()
class REBEAT_PROTOTYPE_API UUE_ReadWriteFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "File IO")
	static FString WriteStringToFile(
		FString Filename,
		FString String,
		bool StartOfRow,
		bool& bOutSuccess,
		FString& OutInfoMsg
	);
};