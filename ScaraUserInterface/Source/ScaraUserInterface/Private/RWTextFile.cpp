// Fill out your copyright notice in the Description page of Project Settings.
#include<fstream>
#include<iostream>
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "RWTextFile.h"
using namespace std;


bool URWTextFile::LoadTxt(FString FileNameA, FString& SaveTextA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));
}


bool URWTextFile::SaveTxt(FString SaveTextB, FString FileNameB)
{ // let's first try just to store one string and take from it the x y and z parts 

	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB));
}

bool URWTextFile::LoadTxtHamza(FString FileNameA, FString& SaveTextA)
{ // let's not worry about the blueprint variable for now this will be resolved later 
	// let's see now how to make this work first in c++
	ifstream ReadFile(*(FPaths::GameDir() + FileNameA));
	if (!ReadFile) {
		UE_LOG(LogTemp, Error, TEXT("couldn't open file To Read"));
		ReadFile.close();
		return false;
	}

	else {
		// Read from file
		UE_LOG(LogTemp, Error, TEXT("TextFileOpenedCorrectlyForReading"));
		ReadFile.close();
		return true;
	}
}



bool URWTextFile::SaveTxtHamza(FString SaveTextB, FString FileNameB)
{
	ofstream MyFile(*(FPaths::GameDir() + FileNameB));
	// we won't have problems with saving in a file but we will have problems that we should handle especially with the reading from a file 
	if (!MyFile) {
		UE_LOG(LogTemp, Error, TEXT("couldn't open file To Write"));
		MyFile.close();
		return false;
	}

	else {
		// Write to the file
		UE_LOG(LogTemp, Error, TEXT("TextFileOpenedCorrectlyForWriting"));
		MyFile << "Files can be tricky, but it is fun enough yaaay !!!!!!!!!!!! !";



		MyFile.close();
		return true;
	}
}

// now i should see how i could read all the strings one by one and then transfer them one by one to the arduino later 
// here now i suppose that i can read a line in a file store each element into a variable and then send it to arduino via a loop 
// so the fstream library is working correctly i was just worried but how to create bluprints from c++ but now it appears to be freaking easy 

