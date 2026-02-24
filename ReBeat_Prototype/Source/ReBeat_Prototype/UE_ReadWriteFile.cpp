#include "UE_ReadWriteFile.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"

FString UUE_ReadWriteFile::WriteStringToFile(
	FString Filename,
	FString String,
	bool StartOfRow,
	bool& bOutSuccess,
	FString& OutInfoMsg)
{
	if(StartOfRow)
	{
		String = "\n" + String;
	}

	FString FilePath = FPaths::ProjectDir() + "/Data-Output/" + Filename;

	if (!FFileHelper::SaveStringToFile(
		String + ", ",
		*FilePath,
		FFileHelper::EEncodingOptions::AutoDetect,
		&IFileManager::Get(),
		FILEWRITE_Append))
	{
		bOutSuccess = false;
		OutInfoMsg = "Failed to append to file.";
		return FString();
	}

	bOutSuccess = true;
	OutInfoMsg = "Successfully appended to file at" + FPaths::ProjectDir() + "/Data-Output/" + Filename;
	return FString();
}