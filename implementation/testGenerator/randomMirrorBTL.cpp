//	randomMirrorBTL
//	randomMirrorBTL.cpp
//Trevor Brooks
//Using C++ Std Version 3.0
//Edited and compiled in VS 2015

//-------------
// C++ includes
//-------------

#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

//-----------------
// Global constants
//-----------------
const int NMBR_TESTS = 20; // How many test files to generate.
const int MAX_CASES = 15; //How many cases in each file (max).
const int MIN_CASES = 5; //How many cases in each file (min).
const int MAX_PATTERN_SIZE = 10;
const int NUM_TRANSFORMATIONS = 8;
const std::string PROJECT_CODE = "randomFiles/mirrorBTL"; 
		//We use this to label the files.
const std::string input = "in.txt"; //Labels that generated file should be input.
const std::string output = "out.txt";
const int transformationMatrix[8][3] = { {0,0,0},{1,0,1},
						{1,1,0}, {0,1,1}, {0,1,0}, {0,0,1}, {1,0,0},
						{1,1,1} };

const std::string	transformationMessage[] = { 
		" was preserved."," was rotated 90 degrees.",
		" was rotated 180 degrees."," was rotated 270 degrees.",
		" was reflected vertically.",
		" was reflected vertically and rotated 90 degrees.",
		" was reflected vertically and rotated 180 degrees.",
		" was reflected vertically and rotated 270 degrees.",
		" was improperly transformed." };

char originalImage[MAX_PATTERN_SIZE][MAX_PATTERN_SIZE];
char newImage[MAX_PATTERN_SIZE][MAX_PATTERN_SIZE];

/** ******************************************************
DESCRIPTION - main
This function generates nine files for inputing into a service station program.
The output created for each file should be a valid test.

COMPILE INSTRUCTIONS
To compile and run on Katie:
g++ -std=c++11 -c randomMirrorBTL.cpp
#g++ -o randomMirrorBTL randomMirrorBTL.o
./randomMirrorBTL

REQUIREMENTS
R01	randomMirrorBTL is coded in C++.
R02	The source file will be in compliance 
	with the MTM C++ Source File standard 3.0.
R03	The application will be launched from an executable file.
R04 A series of NMBR_TESTS output files will be created.
R05 The input file names will be in form of mirrorBTLXXin.txt
	where XX is the two digit representation
	of the test case number.
R06 The output file names will be in form of 
	mirrorBTLXXout.txt where XX is the two digit representation
	of the test case number.
R07	Each file will have between MIN_CASES and MAX_CASES cases.
R08	Each case will have a patternSize between 1 and 10 inclusive.
R09	The first line of each case will be the patternSize.
R09.	The following patternSize lines are made up of the patterns.
R10.	Each pattern line has patternSize characters followed 
		by a space and then another patternSize characters.
R11.	The first set of patternSize characters is the row of the original image.
R12.	The second set of patternSize characters is the 
		row of the transformed image.
R13.	The two allowed characters for the images are a period ‘.’ and ‘X’
R14.	The variable patternNum corresponds to the number of the pattern.
R15.	The output is a sentence on its own line output to stdout.
			a.	If the image was rotated by 90, 180, or 270 degrees 
				“Pattern XX was rotated ZZ degrees.” is output, 
				where XX is the patternNum of the pattern and ZZ 
				is the rotation angle.
			b.	If the image was vertically reflected “Pattern XX was 
				reflected vertically.” is output where XX is the patternNum.
			c.	If the image was reflected and then rotated, “Pattern XX 
				was reflected vertically and rotated ZZ degrees.” is output,
				where XX is the patternNum and ZZ is the number of degrees 
				it was reflected.
			d.	If no changes were made to the pattern “Pattern XX was preserved.”
				is output, where XX is the patternNum.
			e.	If none of the above is true, “Pattern XX was 
				improperly transformed.” is output, where XX is the patternNum.



DESIGN
Significant Data Items/Structures
--------------------------------------------

const int NMBR_TESTS = 20; // How many test files to generate.
const int MAX_CASES = 15; //How many cases in each file (max).
const int MIN_CASES = 5; //How many cases in each file (min).
const int MAX_PATTERN_SIZE = 10;
const int NUM_TRANSFORMATIONS = 8;
const std::string PROJECT_CODE = "mirrorBTL"; //We use this to label the files.
const std::string input = "in.txt"; //Labels that generated file should be input.
const std::string output = "out.txt"
const int transformationMatrix[8][3] = {{0,0,0},{1,0,1},
	{1,1,0}, {0,1,1}, {0,1,0}, {0,0,1}, {1,0,0},
	 {1,1,1}};

const std::string	transformationMessage[] = {
		" was preserved."," was rotated 90 degrees.",
		" was rotated 180 degrees."," was rotated 270 degrees.",
		" was reflected vertically.",
		" was reflected vertically and rotated 90 degrees.",
		" was reflected vertically and rotated 180 degrees.",
		" was reflected vertically and rotated 270 degrees.",
		" was improperly transformed."};
int nmbrCases, patternNum, patternSize;

Solution Analysis
-----------------------
Using the random function we can generate files for input.


Algorithm
-------------
A00 Define:
const int NMBR_TESTS = 20; // How many test files to generate.
const int MAX_CASES = 20; //How many cases in each file (max).
const int MIN_CASES = 5; //How many cases in each file (min).
const int MAX_PATTERN_SIZE = 10;
const int NUM_TRANSFORMATIONS = 8;
const std::string PROJECT_CODE = "mirrorBTL"; //We use this to label the files.
const std::string input = "in.txt"; //Labels that generated file should be input.
const std::string output = "out.txt"
const int transformationMatrix[8][3] = {{0,0,0},{1,0,1},
	{1,1,0}, {0,1,1}, {0,1,0}, {0,0,1}, {1,0,0},
	 {1,1,1}};

const std::string	transformationMessage[] = {
		" was preserved."," was rotated 90 degrees.",
		" was rotated 180 degrees."," was rotated 270 degrees.",
		" was reflected vertically.",
		" was reflected vertically and rotated 90 degrees.",
		" was reflected vertically and rotated 180 degrees.",
		" was reflected vertically and rotated 270 degrees.",
		" was improperly transformed."};
int nmbrCases, patternNum, patternSize;

A01 For (testNum iterates from 1 to NMBR_TESTS) { 
A02		Set nmbrCases to a random number between MAX_CASES and MIN_CASES 
		Set outputString to an empty string

A03		Open inputFile and outputFile

A04		For (caseNum iterates from 1 to nmbrCases) { 
A05			Set patternSize to a random number up to MAX_PATTERN_SIZE
A06			Call generatePatterns(patternSize)
A07			Call outputPattern(inputFile, patternSize); 
		}//for
	}//for
A08	Return

L09	int generatePatterns(int patternSize) {
L10		Set transformationNdx to a 
			random number between 1 and NUM_TRANSFORMATIONS; 
A11		for (yNdx iterates from 0 to patternSize) { 
A12			for (xNdx iterates from 0 to patternSize) { 
A13				Set transformedXNdx to xNdx;
				Set transformedYNdx to yNdx;
				if (transformationNdx is not equal to 8) {
A15					if (transformationMatrix[transformationNdx][2] is equal to 1) {
A16						Set transformedXNdx to yNdx;
						Set transformedYNdx to xNdx;
					}//if
A17					if (transformationMatrix
						[transformationNdx][0] is equal to 1) {
A18						Set transformedXNdx to patternSize - 1 - transformedXNdx;
					}//if
A19					if (transformationMatrix
						[transformationNdx][1] is equal to 1) {
A20						Set transformedYNdx to patternSize - 1 - transformedYNdx;
					}//if

A21					if (rand() % 2 is less than 1) {
A22						Set originalImage[xNdx][yNdx] to '.';
						Set newImage[transformedXNdx][transformedYNdx] to '.';
					}//if
A23					else {
A24						Set originalImage[xNdx][yNdx] to 'X';
						Set newImage[transformedXNdx][transformedYNdx] to 'X';
					}//else
				}//if
A25				else {
A26					if (rand() % 2 is less than 1) {
A27						Set originalImage[xNdx][yNdx] to '.';
					}//if
A28					else {
A29						Set originalImage[xNdx][yNdx] to 'X';
					}//else
A30					if (rand() % 2 is less than 1) {
A31						Set newImage[xNdx][yNdx] to '.';
					}//if
A32					else {
A33						Set newImage[xNdx][yNdx] to 'X';
					}//else
				}//else
			}//for xNdx
		}//for yNdx
A34		return transformationNdx;
	}//generatePatterns

A35	void outputPattern(std::ofstream& inputFile, int patternSize) {
A36		inputFile << patternSize << std::endl;
A37		for (int yNdx = 0; yNdx < patternSize; yNdx++) {
A38			for (int originalXNdx = 0; 
				originalXNdx < patternSize; originalXNdx++) {
A39				Set inputFile to inputFile + originalImage[originalXNdx][yNdx];
			}//for
A40			Set inputFile to inputFile + " ";
A41			for (int newXNdx = 0; newXNdx < patternSize; newXNdx++) {
A42				Set inputFile to inputFile + newImage[newXNdx][yNdx];
			}//for
A43			Set inputFile to inputFile + std::endl;
		}//for
	}//outputPattern

*********************************************************/

int generatePatterns(int patternSize) {/*L09*/
	int transformationNdx = (int)(rand() % (NUM_TRANSFORMATIONS + 1)); /*L10*/
	int transformedXNdx, transformedYNdx;
	for (int yNdx = 0; yNdx < patternSize; yNdx++) { /*L11*/
		for (int xNdx = 0; xNdx < patternSize; xNdx++) { /*L12*/
			transformedXNdx = xNdx;/*L13*/
			transformedYNdx = yNdx;
			if (transformationNdx != 8) {/*L14*/
				if (transformationMatrix[transformationNdx][2] == 1) {/*L15*/
					transformedXNdx = yNdx;/*L16*/
					transformedYNdx = xNdx;
				}//if
				if (transformationMatrix[transformationNdx][0] == 1) {/*L17*/
					transformedXNdx = patternSize - 1 - transformedXNdx;/*L18*/
				}//if
				if (transformationMatrix[transformationNdx][1] == 1) {/*L19*/
					transformedYNdx = patternSize - 1 - transformedYNdx;/*L20*/
				}//if

				if (rand() % 2 < 1) {/*L21*/
					originalImage[xNdx][yNdx] = '.';/*L22*/
					newImage[transformedXNdx][transformedYNdx] = '.';
				}//if
				else {/*L23*/
					originalImage[xNdx][yNdx] = 'X';/*L24*/
					newImage[transformedXNdx][transformedYNdx] = 'X';
				}//else
			}//if
			else {/*L25*/
				if (rand() % 2 < 1) {/*L26*/
					originalImage[xNdx][yNdx] = '.';/*L27*/
				}//if
				else {/*L28*/
					originalImage[xNdx][yNdx] = 'X';/*L29*/
				}//else
				if (rand() % 2 < 1) {/*L30*/
					newImage[xNdx][yNdx] = '.';/*L31*/
				}//if
				else {/*L32*/
					newImage[xNdx][yNdx] = 'X';/*L33*/
				}//else
			}//else
		}//for xNdx
	}//for yNdx
	return transformationNdx;/*L34*/
}//generatePatterns

void outputPattern(std::ofstream& inputFile, int patternSize) {/*L35*/
	inputFile << patternSize << std::endl;/*L36*/
	for (int yNdx = 0; yNdx < patternSize; yNdx++) {
		/*L37*/
		for (int originalXNdx = 0; originalXNdx < patternSize; originalXNdx++) {/*L38*/
			inputFile << originalImage[originalXNdx][yNdx];/*L39*/
		}//for
		inputFile << " ";/*L40*/
		for (int newXNdx = 0; newXNdx < patternSize; newXNdx++) {/*L41*/
			inputFile << newImage[newXNdx][yNdx];/*L42*/
		}//for
		inputFile << std::endl;/*L43*/
	}//for
}//outPattern

int main(int argc, const char * argv[]) {
	/*A00 Define*/
	int nmbrCases, patternSize;
	std::string outputString;

	srand(time(NULL));
	for (int testNum = 1; testNum <= NMBR_TESTS; testNum++) { /*L01*/
		nmbrCases = (int)(rand() % (MAX_CASES - MIN_CASES + 1)) + MIN_CASES; 
			/*L02*/
		outputString = "";
		//Create output stream.
		std::ofstream inputFile, outputFile; /*L03*/
		//Open the output file. Removes old content from file listed.
		inputFile.open(PROJECT_CODE + 
				std::to_string(testNum) + input, std::ios::trunc);
		outputFile.open(PROJECT_CODE + 
				std::to_string(testNum) + output, std::ios::trunc);
		for (int caseNum = 1; caseNum <= nmbrCases; caseNum++) { /*L04*/
			patternSize = (int)(rand() % (MAX_PATTERN_SIZE)+1); /*L05*/
			generatePatterns(patternSize); /*L06*/
			outputPattern(inputFile, patternSize); /*L07*/
		}//for

	}//for
	return 0; /*L08*/
}
