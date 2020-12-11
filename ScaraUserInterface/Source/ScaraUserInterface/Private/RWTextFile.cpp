// Fill out your copyright notice in the Description page of Project Settings.
#include "RWTextFile.h"
#include<fstream>
#include<string>
#include<iostream>
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

// the file pointer 
ifstream ReadFile;
int L = 150, l = 150, D = 280;

using namespace std;

/*bool URWTextFile::LoadTxt(FString FileNameA, FString& SaveTextA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));
}*/
/*bool URWTextFile::SaveTxt(FString SaveTextB, FString FileNameB)
{ // let's first try just to store one string and take from it the x y and z parts

	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB));
}*/

bool URWTextFile::OpenFile(FString File_NameRead) {
	ReadFile.open(*(FPaths::GameDir() + File_NameRead));
	if (!ReadFile) {
		UE_LOG(LogTemp, Error, TEXT("couldn't open file To Read"));
		ReadFile.close();
		return false;
	}
	UE_LOG(LogTemp, Warning, TEXT("TextFileOpenedCorrectlyForReading"));
	return true;
}

void URWTextFile::CloseFile() {
	ReadFile.close();
}

int32 URWTextFile::CountLines(int32& LINES) {
	string line;
	while (std::getline(ReadFile, line)) {
		++LINES;
	}
	UE_LOG(LogTemp, Warning, TEXT("LinesNumber:%d"), LINES);
	ReadFile.clear();
	ReadFile.seekg(0);
	return LINES;
}


/*void URWTextFile::LoadTxtHamzaOld(const FString File_NameRead, int32& x_coordinate, int32& y_coordinate, int32& z_coordinate)
{
	// let's see now how to make this work first in c++
	ifstream ReadFile2(*(FPaths::GameDir() + File_NameRead));
	if (!ReadFile2) {
		UE_LOG(LogTemp, Error, TEXT("couldn't open file To Read"));
		ReadFile2.close();
	}

	else {
		// what this function does is that it iterates trough a file and take the x and y coordinates and  z
		UE_LOG(LogTemp, Warning, TEXT("TextFileOpenedCorrectlyForReading"));
		ReadFile2 >> x_coordinate >> y_coordinate >> z_coordinate;
		UE_LOG(LogTemp, Warning, TEXT("x=%d y=%d z=%d"), x_coordinate, y_coordinate, z_coordinate);
		ReadFile2.close();
	}
}*/

void URWTextFile::LoadTxtHamza(int32& x_coordinate, int32& y_coordinate, int32& z_coordinate)
{
	ReadFile >> x_coordinate >> y_coordinate >> z_coordinate;
	// here we implement those variables to the equations and then we will return the angle values that we want 
	UE_LOG(LogTemp, Warning, TEXT("x=%d y=%d z=%d"), x_coordinate, y_coordinate, z_coordinate);
}

bool URWTextFile::CalculateAngles(int32 x_coordinate, int32 y_coordinate, int32  z_coordinate, int32& o1_Angle, int32& o2_Angle,
	int32& z_coord) {

	int x = x_coordinate;
	int y = y_coordinate;
	z_coord = z_coordinate;
	float b = sqrt(((D - x) * (D - x) + y * y));
	float a = sqrt(x * x + y * y);
	float teta1 = acos((L * L + a * a - l * l) / (2 * L * a)) + atan(y / x);
	float teta2 = PI - acos((L * L + b * b - l * l) / (2 * L * b)) - atan((D - x) / b);
	teta1 = (teta1 * 180.0) / PI;
	teta2 = (teta2 * 180.0) / PI;
	int tetadyn1 = (240 - teta1) * 1023 / 300;
	int tetadyn2 = (150 - teta2) * 1023 / 300;
	o1_Angle = tetadyn1;
	o2_Angle = tetadyn2;

	UE_LOG(LogTemp, Warning, TEXT("x=%d y=%d z=%d"), o1_Angle, o2_Angle, z_coord);
	if (0<o1_Angle && o1_Angle<1023 && 0 < o2_Angle && o2_Angle < 1023) {
		return true;
	}
	else {
		return false;
	}
}

/*bool URWTextFile::SaveTxtHamza(FString TextWrite, FString File_NameWrite)
{
	ofstream MyFile(*(FPaths::GameDir() + File_NameWrite));
	// we won't have problems with saving in a file but we will have problems that we should handle especially with the reading from a file
	if (!MyFile) {
		UE_LOG(LogTemp, Error, TEXT("couldn't open file To Write"));
		MyFile.close();
		return false;
	}

	else {
		// Write to the file
		UE_LOG(LogTemp, Warning, TEXT("TextFileOpenedCorrectlyForWriting"));
		string test = "we are just testing here";
		//MyFile << x;

		MyFile.close();
		return true;
	}
}*/

/*int32 URWTextFile::ReturnCoodinate(FString Coordinate_Name) {

	if (Coordinate_Name.Equals("X")) {
		return x_coodinate;
	}
	else if (Coordinate_Name.Equals("Y")) {
		return y_coodinate;
	}
	else if (Coordinate_Name.Equals("Z")) {
		return z_coodinate;
	}
	else {
		return 0;
	}
}*/

// cool so now we are acceding our variables one line by line and that shit is dope .


























