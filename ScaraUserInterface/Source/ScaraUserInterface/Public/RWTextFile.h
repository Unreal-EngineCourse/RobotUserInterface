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
		static bool  CalculateAngles(float x, float y, int32  z_coordinate,float & o1_Angle, float & o2_Angle, 
			int32 &  z_coord);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "ConvertAngles"))
		static bool  ConvertAngles(float O1_entree, float O2_entree, float& o1_Sortie, float& o2_Sortie);


	/*bool constraint1(float O1, float O2);
	bool constraint2(float O1, float O2);
	bool interdroite(float x1, float y1, float l1, float x2, float y2, float l2, float O1, float O2);
	bool appart(float x1, float x11, float xi);
	void calcul_xy(float  O1, float O2);*/

};
