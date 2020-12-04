// Fill out your copyright notice in the Description page of Project Settings.
#include "RWTextFile.h"
#include<fstream>
#include<string>
#include<iostream>
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

using namespace std;
bool URWTextFile::LoadTxt(FString FileNameA, FString& SaveTextA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));
}


bool URWTextFile::SaveTxt(FString SaveTextB, FString FileNameB)
{ // let's first try just to store one string and take from it the x y and z parts 

	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB));
}

FString URWTextFile::LoadTxtHamza(FString TextRead, FString File_NameRead)
{ // let's not worry about the blueprint variable for now this will be resolved later 
	// let's see now how to make this work first in c++
	ifstream ReadFile(*(FPaths::GameDir() + File_NameRead));
	if (!ReadFile) {
		UE_LOG(LogTemp, Error, TEXT("couldn't open file To Read"));
		ReadFile.close();
		return "";
	}

	else {
		// Read from file
		UE_LOG(LogTemp, Warning, TEXT("TextFileOpenedCorrectlyForReading"));
		// Reading The First Line Using The C++ method 
		string Take_Line{ 0 };
		char caractereActuel{ 0 };
		string x_coordinate="helloo";

		do
		{
			x_coordinate += caractereActuel;
			ReadFile.get(caractereActuel);

		} while (caractereActuel != '\n');
		TextRead = x_coordinate.c_str();

		/*getline(ReadFile, Take_Line);
		TextRead = Take_Line.c_str();*/

		return TextRead;
		ReadFile.close();
	}
}



bool URWTextFile::SaveTxtHamza(FString TextWrite, FString File_NameWrite)
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
}

// now i should see how i could read all the strings one by one and then transfer them one by one to the arduino later 
// here now i suppose that i can read a line in a file store each element into a variable and then send it to arduino via a loop 
// so the fstream library is working correctly i was just worried but how to create bluprints from c++ but now it appears to be freaking easy 

// we should do the first try for a normal x and y ;
































