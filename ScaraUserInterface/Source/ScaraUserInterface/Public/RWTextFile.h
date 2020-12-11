// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include<iostream>
#include<string>
using namespace std;
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RWTextFile.generated.h"

/**
 *
 */
UCLASS()
class SCARAUSERINTERFACE_API URWTextFile : public UBlueprintFunctionLibrary
{
GENERATED_BODY() public:
	/*UFUNCTION(BlueprintPure, Category = "Custom", meta = (Keywords = "LoadTxt"))
		static bool LoadTxt(FString FileNameA, FString& SaveTextA);*/

	/*UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "SaveTxt"))
		static bool SaveTxt(FString SaveTextB, FString FileNameB);*/

	/*UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "LoadTxtHamzaOld"))
		static void  LoadTxtHamzaOld(const FString File_NameRead, int32& x_coordinate, int32& y_coordinate, int32& z_coordinate);*/

	/*UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "SaveTxtHamza"))
			static bool SaveTxtHamza(FString TextWrite, FString File_NameWrite);*/

	/*UFUNCTION(BlueprintPure, Category = "Custom", meta = (Keywords = "Return Coordinate"))
				static int32 ReturnCoodinate(FString Coordinate_Name);*/

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "OpenFile"))
		static bool OpenFile(FString File_NameRead);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "CloseFile"))
		static void CloseFile();

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "CountLines"))
		static int32 CountLines(int32& LINES);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "LoadTxtHamza"))
		static void  LoadTxtHamza(int32 & x_coordinate, int32 & y_coordinate, int32 & z_coordinate);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "CalculateAngles"))
		static bool  CalculateAngles(int32 x_coordinate, int32 y_coordinate, int32  z_coordinate,int32 & o1_Angle, int32 & o2_Angle, 
			int32 &  z_coord);
};
