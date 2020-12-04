// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RWTextFile.generated.h"

/**
 * 
 */
UCLASS()
class SCARAUSERINTERFACE_API URWTextFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure, Category = "Custom", meta = (Keywords = "LoadTxt"))
		static bool LoadTxt(FString FileNameA, FString& SaveTextA);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "SaveTxt"))
		static bool SaveTxt(FString SaveTextB, FString FileNameB);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "SaveTxtHamza"))
		static bool SaveTxtHamza(FString SaveTextB, FString FileNameB);

	UFUNCTION(BlueprintPure, Category = "Custom", meta = (Keywords = "LoadTxtHamza"))
		static bool LoadTxtHamza(FString FileNameA, FString& SaveTextA);

};


