// Fill out your copyright notice in the Description page of Project Settings.
#include "RWTextFile.h"
#include<fstream>
#include <math.h>
#include<algorithm>
#include<string>
#include<iostream>
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"


#define PI 3,141592653589
float Ox = 20, Oy = 20;
float l1 = 146, l2 = 150, l3 = 150, l4 = 149, a = 100, e = 38, d1 = 150, d2 = 150;
float O[] = { 0,0,0,0 };
float x2, x3, y2, y3;
int m = 150, i;

// the file pointer 
ifstream ReadFile;
//int L = 150, l = 150, D = 280;

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

/*bool URWTextFile::CalculateAngles(int32 x_coordinate, int32 y_coordinate, int32  z_coordinate, int32& o1_Angle, int32& o2_Angle,
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
}*/

bool URWTextFile::CalculateAngles(float x, float y, int32  z_coordinate, float& o1_Angle, float& o2_Angle,
	int32& z_coord) {
	float A, ka, kb, kc, D1;
	float a1;
	a1 = a;
	A = (x - a1) * (x - a1) + l1 * l1 + y * y - l2 * l2;
	ka = (A + 2 * (x - a1) * l1);
	kb = -4 * l1 * y;
	kc = A - 2 * (x - a1) * l1;
	D1 = kb * kb - 4 * kc * ka;
	if (ka == 0) {
		if (kb == 0) {
			if (kc == 0) {
				O[0] = 2;
				O[1] = 2;
			}
			else {
				O[0] = PI;
				O[1] = PI;
			}
		}
		else {
			O[0] = 2 * atan(-kc / kb);
			O[1] = 2 * atan(-kc / kb);
		}
	}
	else if (D1 >= 0) {
		O[0] = 2 * atan((-kb + sqrt(D1)) / (2 * ka));
		O[1] = 2 * atan((-kb - sqrt(D1)) / (2 * ka));
	}
	else {
		/*
		O[0] = 100;
		O[1] = 100;
		O[2] = 100;
		O[3] = 100;*/
		return false;
	}
	a1 = -a;
	A = (x - a1) * (x - a1) + l4 * l4 + y * y - l3 * l3;
	ka = (A + 2 * (x - a1) * l4);
	kb = -4 * l4 * y;
	kc = A - 2 * (x - a1) * l4;
	D1 = kb * kb - 4 * kc * ka;
	if (ka == 0) {
		if (kb == 0) {
			if (kc == 0) {
				O[2] = 2;
				O[3] = 2;
			}
			else {
				O[2] = PI;
				O[3] = PI;
			}
		}
		else {
			O[2] = 2 * atan(-kc / kb);
			O[3] = 2 * atan(-kc / kb);
		}
	}
	else if (D1 >= 0) {
		O[2] = 2 * atan((-kb + sqrt(D1)) / (2 * ka));
		O[3] = 2 * atan((-kb - sqrt(D1)) / (2 * ka));
	}
	else {
		/*O[0] = 100;
		O[1] = 100;
		O[2] = 100;
		O[3] = 100;*/
		return false;
	}
	z_coord = z_coordinate;
	o1_Angle = O[0];
	o2_Angle = O[2];

	UE_LOG(LogTemp, Warning, TEXT("x=%d y=%d z=%d"), o1_Angle, o2_Angle, z_coord);
	return true;

}

bool  URWTextFile::ConvertAngles(float O1_entree, float O2_entree, float& o1_Sortie, float& o2_Sortie) {
	// for o1
	if (O1_entree >= -90 && O1_entree <= 180) {
		O1_entree = O1_entree + 90;
	}
	else if (O1_entree >= -180 && O1_entree <= -90) {
		O1_entree = O1_entree + 450;
	}

	O1_entree = O1_entree * 4095 / 360;
	o1_Sortie = 4095 - O1_entree;
	// for o2
	if (O2_entree >= -90 && O2_entree <= 180) {
		O2_entree = O2_entree + 90;
	}
	else if (O2_entree >= -180 && O2_entree <= -90) {
		O2_entree = O2_entree + 450;
	}

	O2_entree = O2_entree * 4095 / 360;

	o2_Sortie = 4095 - O2_entree;
	return true;

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

/*bool URWTextFile::constraint1(float O1, float O2) {
	float p = 0.2;
	float d = sqrt(pow((l1 * cos(O1) - l3 * cos(O2) + 2 * a), 2) + pow((l1 * sin(O1) - l3 * sin(O2)), 2));
	if (abs(l1 + l3 - d) <= p) {
		return true;
	}
	else return false;
}*/

/*bool URWTextFile::constraint2(float O1, float O2) {
	float e1 = e / 2;
	if (interdroite(sin(O2) * e1 - a, -cos(O2) * e1, d1, -sin(O1) * e1 + a, cos(O1) * e1, d2, O2, O1) || interdroite(-sin(O2) * e1 - a, +cos(O2) * e1 - a, d1, +sin(O1) * e1 + a, -cos(O1) * e1, d2, O2, O1) || (pow(l1 * cos(O1) + 2 * a - l4 * cos(O2), 2) + pow(l1 * sin(O1) - l4 * sin(O2), 2) <= 1.4 * e * e)) {

		return true;
	}
	else return false;
}*/

/*bool URWTextFile::interdroite(float x1, float y1, float l1, float x2, float y2, float l2, float O1, float O2) {
	float yi = l1 + 1;
	float a1, a2, b1, b2, xi;
	float x11 = x1 + l1 * cos(O1);
	float y11 = y1 + l1 * sin(O1);
	float x22 = x2 + l2 * cos(O2);
	float y22 = y2 + l2 * sin(O2);
	if ((O1 != PI / 2) && (O2 != PI / 2)) {
		a1 = tan(O1);
		a2 = tan(O2);
		b1 = y1 - a1 * x1;
		b2 = y2 - a2 * x2;
		xi = (b1 - b2) / (a2 - a1);
		yi = a1 * xi + b1;
	}
	else if ((O1 == PI / 2) && (O2 != PI / 2)) {
		a2 = tan(O2);
		b2 = y2 - a2 * x2;
		xi = x1;
		yi = a2 * xi + b2;
	}
	else if ((O1 != PI / 2) && (O2 == PI / 2)) {
		a1 = tan(O1);
		b1 = y1 - a1 * x1;
		xi = x2;
		yi = a1 * xi + b1;
	}
	else {
		return false;
	}

	if (appart(x1, x11, xi) && appart(y1, y11, yi) && appart(x2, x22, xi) && appart(y2, y22, yi)) {
		return true;
	}
	else { return false; }

}*/
/*bool URWTextFile::appart(float x1, float x11, float xi) {
	if (xi >= min(x1, x11) && xi <= max(x1, x11)) {
		return true;
	}
	else {
		return false;
	}
}*/

/*void URWTextFile::calcul_xy(float  O1, float O2) {
	float  x0 = a + l1 * cos(O1), y0 = l1 * sin(O1), r0 = l2, x1 = -a + l3 * cos(O2), y1 = l3 * sin(O2), r1 = l4;
	float X1 = 0, X2 = 0, Y1 = 0, Y2 = 0;
	float k, A, B, C, D, N;
	if (y0 == y1) {
		k = (r1 * r1 - r0 * r0 - x1 * x1 + x0 * x0) / (2 * (x0 - x1));
		A = 1;
		B = -2 * y1;
		C = x1 * x1 + k * k - 2 * x1 * k + y1 * y1 - r1 * r1;
		D = sqrt(B * B - 4 * A * C);
		X1 = k;
		X2 = k;
		Y1 = (-B + D) / (2 * A);
		Y2 = (-B - D) / (2 * A);
		if (X1 * X1 + Y1 * Y1 < X2 * X2 + Y2 * Y2) {
			x2 = X1; y2 = Y1; x3 = X2; x3 = Y2;
		}
		else {
			x2 = X2; y2 = Y2; x3 = X1; y3 = Y1;
		}
	}
	else if (y0 == y1 && x0 == x1) { x1 = 5000; y1 = 5000; x2 = 5000; y2 = 5000; }
	else if (pow(x1 - x0, 2) + pow(y1 - y0, 2) <= pow(l1 + l2, 2)) {
		N = (r1 * r1 - r0 * r0 - x1 * x1 + x0 * x0 - y1 * y1 + y0 * y0) / (2 * (y0 - y1));
		A = pow((x0 - x1) / (y0 - y1), 2) + 1;
		B = 2 * y0 * (x0 - x1) / (y0 - y1) - 2 * N * (x0 - x1) / (y0 - y1) - 2 * x0;
		C = pow(x0, 2) + pow(y0, 2) + pow(N, 2) - (r0 * r0) - (2 * y0 * N);
		D = sqrt(B * B - 4 * A * C);
		X1 = (-B + D) / (2 * A);
		X2 = (-B - D) / (2 * A);
		Y1 = N - X1 * (x0 - x1) / (y0 - y1);
		Y2 = N - X2 * (x0 - x1) / (y0 - y1);
		if (X1 * X1 + Y1 * Y1 < X2 * X2 + Y2 * Y2) {
			x2 = X1; y2 = Y1; x3 = X2; x3 = Y2;
		}
		else {
			x2 = X2; y2 = Y2; x3 = X1; y3 = Y1;
		}
	}
	else { x1 = 4000; y1 = 4000; x2 = 4000; y2 = 4000; }
	cout << x1 << "** " << y1 << "** " << x2 << "** " << y2 << endl;
}*/

























