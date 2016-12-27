//	MirrorBTL
//	MirrorBTL.cpp
//Trevor Brooks
//Using C++ Std Version 3.0
//Edited and compiled in VS 2015

//-------------
// C++ includes
//-------------

#include <stdlib.h>
#include <iostream>
#include <string>

/** ******************************************************
DESCRIPTION - main


REQUIREMENTS
The priority of these requirements is imperative.

**Constraints
R01.	MirrorBTL is coded in C++.
Validation: Inspection and Test (Build)
R02.	The source file for ServiceStationBTL is in compliance with
		MTM C++ Source File Standard v4.0.
Validation: Inspection
R03.	The SMDS conforms to version 4.2 of the standard.
**Preconditions
R04.	The input file is well-formed, follows the input/output requirements,
		and exists.
**Invocation
R05.	Launch application execution file.
Validation: Test
**Input/Ouput
R06.	Input consists of an unknown number of patterns.
Validation: Test
R07.	Patterns start with a positive integer (patternSize) on its own line 
		that signifies the number of rows and columns in the pattern.
Validation: Inspection
R08.	patternSize is between 1 and 10 inclusive.
Validation:Test
R09.	The following patternSize lines are made up of the patterns.
Validation: Test
R10.	Each pattern line has patternSize characters followed by a space
		and then another patternSize characters.
Validation: Test
R11.	The first set of patternSize characters is the row of the original image.
Validation: Test
R12.	The second set of patternSize characters is the row of the 
		transformed image.
Validation: Test
R13.	The two allowed characters for the images are a period ‘.’ and ‘X’
Validation: Test
R14.	The variable patternNum corresponds to the number of the pattern 
		in the input sequence.
Validation: Test
R15.	The output is a sentence on its own line output to stdout.
Validation: Test
a.	If the image was rotated by 90, 180, or 270 degrees “Pattern XX was 
	rotated ZZ degrees.” is output, where XX is the patternNum of the 
	pattern and ZZ is the rotation angle.
b.	If the image was vertically reflected “Pattern XX was reflected
	vertically.” is output where XX is the patternNum.
c.	If the image was reflected and then rotated, “Pattern XX was reflected 
	vertically and rotated ZZ degrees.” is output, where XX is the 
	patternNum and ZZ is the number of degrees it was reflected.
d.	If no changes were made to the pattern “Pattern XX was preserved.”
	is output, where XX is the patternNum.
e.	If none of the above is true, “Pattern XX was improperly 
	transformed.” is output, where XX is the patternNum.

**Postconditons
R16.	The input file is still in the system.
	  Validation: Inspection
**Testing
R17.	MirrorBTL will be tested using test scripts and test files.
Validation: Inspection
R18.	MirrorBTL will be randomly tested against another student’s version.
Validation: Inspection
**Inspection
None

**Algorithm Correctness Argument
R19.	A correctness algorithm will be provided 
		for both the algorithm and the code.  
Validation: Inspection


SAMPLE RUN(S)
5
X...X ....X
.X... ...X.
...X. .X...
..X.X ..X..
....X XX..X
6
....XX X....X
...X.. X.X...
XX..X. .X..X.
..X... ...X.X
...X.. ..X...
..X..X ..X...


2
X. X.
.X .X
4
..X. ...X
XX.. ....
.... XX..
...X ..X.
5
X.... .X...
.X... ..X..
.X... ..X..
...X. ....X
....X X....
4
.X.. ..X.
.X.X X...
.... ..XX
..X. ....
2
.. XX
XX ..

Then stdout should be
Pattern 1 was rotated 90 degrees.
Pattern 2 was rotated 270 degrees.
Pattern 3 was preserved.
Pattern 4 was reflected vertically.
Pattern 5 was improperly transformed.
Pattern 6 was reflected vertically and rotated 270 degrees.
Pattern 7 was rotated 180 degrees.


DESIGN
Significant Data Items/Structures
--------------------------------------------
int[][] transformationMatrix
	Rows relate to the various transformations
	Columns relates to the following
		1st column: invertX – If 1, read the X values from high to low
		2nd column: invertY	- If 1, read the Y values from high to low
		3rd column: invertXYPriority – If 1, iterate 
					y then x instead of x and then y
	Preserve			              [[0,0,0],
	90 degree	 		               [1,0,1],
	180 Degree	 		             [1,1,0],
	270 degree	 		             [0,1,1],
	Reflection	 		             [0,1,0],
	Reflection and 90 Degree	   [0,0,1],
	Reflection and 180 Degree	   [1,0,0],
	Reflection and 270 Degree	   [1,1,1]]
	The order of rows also accounts for the amount of work.
int[][] 	originalImage;
int[][] 	newImage;
char	originalValue, transformedValue;
int 	NUM_TRANSFORMATIONS = 8;
int MAX_SIZE = 10;
int 	patternNum, patternSize, transformedXNdx, transformedYNdx;
Boolean isValidTransformation;
String[]	transformationMessage;


Solution Analysis
-----------------------
The problem will be solved by looking at the input array and by looking at the
  indices in different orders, checking to see if there is a valid
  transformation that has been applied to create the output array.
This works because if we know where each transformations origin is, and how
  to iterate over the x and y indices then we can read the new image and check
  each index against the original image. The benefit of this method is that we
  can stop once we decide that the images do not follow the transformation we
  are checking. transformationMatrix holds the information about how to read
  the newImage array to compare it against the originalImage.


Algorithm
-------------
A00	Define:
		int[][] transformationMatrix
		int[][] 	originalImage;
int[][] 	newImage;
char	originalValue, transformedValue;
int 	NUM_TRANSFORMATIONS = 8;
int 	patternNum, patternSize, transformedXNdx,
transformedYNdx;
Boolean isValidTransformation;
String[]	transformationMessage;
A01	While(stdin is not empty){
A02		Read patternSize from stdin;
A03		For(lineNdx iterates from 0 to patternSize){
A04			Read originalImage and newImage from stdin;
		}//For
A05		For(transformationNdx iterates from 0 to NUM_TRANSFORMATIONS -1){
A06			Set isValidTransformation to true;
A07			For(xNdx iterates from 0 to patternSize -1){
A08				For(yNdx iterates from 0 to patternSize -1){
A09					Set originalValue to newImage[xNdx][yNdx];
	Set transformedXNdx to xNdx;
	Set transformedYNdx to yNdx;
A10					If(transformationMatrix[transformationNdx][2] is
equal to 1){
A11						Set transformedXNdx to yNdx;
		Set transformedYNdx to xNdx;
}
A12					If(transformationMatrix[transformationNdx][0] is
equal to 1){
A13						Set transformedXNdx
to patternSize -1 - transformedXNdx;
}//If
A14					If(transformationMatrix[transformationNdx][1] is
equal to 1){
A15						Set transformedYNdx
to patternSize -1 -transformedYNdx;
}//If

A16					Set transformedValue to
originalImage[transformedXNdx][transformedYNdx];

A17					If(transformedValue is not equal to originalValue){
A18						Set isValidTransformation to false;
Break;
}//If
}//For yNdx
A19				If(isValidTransformation is false){
A20					Break;
}//If
}//For xNdx
A21			If(isValidTransformation is true){

A22				Display “Pattern ” + patternNum + “ ” +
transformationMessage[transformationNdx];
A23				Break;
}//If
		}//For transformationNdx
A24		Set  patternNum to patternNum + 1;
	}//While
A25	Return;


INPUT SPACE PARTITIONS
1.	There is one pattern in the input.
1.1.	patternSize is 1.
1.1.1.	The pattern is preserved.
1.1.2.	The pattern was improper.
1.2.	patternSize is 2.
1.2.1.	The pattern is preserved.
1.2.2.	The pattern is a rotation.
1.2.3.	The pattern is a reflection.
1.2.4.	The pattern is a reflection and a rotation.
1.2.5.	The pattern was improper.
1.3.	patternSize is greater than 2 but at most 10.
1.3.1.	The pattern is preserved.
1.3.2.	The pattern is a rotation.
1.3.3.	The pattern is a reflection.
1.3.4.	The pattern is a reflection and a rotation.
1.3.5.	The pattern was improper.
2.	There are two patterns in the input.
Two patterns that are variations on (1).
3.	There are more than two patterns in the input.
Several patterns that are variations on (1).


TEST CASES
Please see mirrorSMDS_BTL.docx for a grid view of the test cases.
Program can be tested against these test cases by running mirrorUnitTestBTL.sh


ALGORITHM CORRECTNESS ARGUMENT
CR06	A01 continues reading until the end of the file
CR07	patternSize is read in by A02
CR08	originalImage and newImage both are sized 
		when instantiated in A00 to hold
		up to a pattern of size ten
CR09	A03 reads in patternSize lines of input for the patterns
CR10	A04 reads in one line of the patterns
CR11	A04 reads the originalImage first
CR12	After reading the first patternSize characters 
			and consuming the space A04
			reads the pattern information into newImage
CR13	The valid characters are added to the arrays.
CR14	pattternNum is started in A00 with the value 1, patternNum is incremented
		   in A25 by one to increment the number to print, and then patternNum is
		   displayed on A22 so that the output contains the patternNum
CR15	A22 prints out the statement


CODE CORRECTNESS ARGUMENT
CA01	While loop iterates until the stdin is empty
CA02	The first line is read in and contains the patternNum
CA03	lineNdx iterates from 0 to patternSize -1
CA04	Both images are read in from stdin
CA05	The loop iterates through possible transformations
CA06	isValidTransformation is set to true
CA07	xNdx is iterated from 0 to patternSize - 1
CA08	yNdx is iterated from 0 to patternSize - 1
CA09	originalValue, newImage, transformedXNdx, and transformedYNdx are set
CA10	Value from transformationMatrix is checked
CA11	transformedXNdx and transformedYNdx are set
CA12	transformationMatrix value is checked
CA13	transformedXNdx is set
CA14	transformationMatrix is checked
CA15	transformedYNdx is set
CA16	transformedValue is set
CA17	transformedValue is checked against originalValue
CA18	isValidTransformation is set
CA19	isValidTransformation is checked
CA20	Loop is broken
CA21	isValidTransformation is checked
CA22	Output is sent to stdout
CA23	Loop is broken
CA24	patternNum is incremented
CA25	Program returns at end.


*********************************************************/

int main()
{
	/*L00 : DEFINE */
	const int NUM_TRANSFORMATIONS = 8;
	const int MAX_PATTERN_SIZE = 10;
	const int transformationMatrix[8][3] = { {0,0,0},{1,0,1},
		  {1,1,0}, {0,1,1}, {0,1,0}, {0,0,1}, {1,0,0},
		 {1,1,1} };
	std::string line;
	char originalImage[MAX_PATTERN_SIZE][MAX_PATTERN_SIZE];
	char newImage[MAX_PATTERN_SIZE][MAX_PATTERN_SIZE];
	char originalValue, transformedValue;
	int patternNum, patternSize, transformedXNdx, transformedYNdx;
	bool isValidTransformation;
	const std::string	transformationMessage[] = { 
		   " was preserved."," was rotated 90 degrees.",
		   " was rotated 180 degrees."," was rotated 270 degrees.",
		   " was reflected vertically.",
		   " was reflected vertically and rotated 90 degrees.",
		   " was reflected vertically and rotated 180 degrees.",
		   " was reflected vertically and rotated 270 degrees.",
		   " was improperly transformed." };

	patternNum = 1;
	std::getline(std::cin, line);
	while (line.length() > 0) { /*L01*/
		patternSize = std::stoi(line); /*L02*/
		for (int lineNdx = 0; lineNdx < patternSize; lineNdx++) { /*L03*/
			std::getline(std::cin, line);
			//Read originalImage and newImage from stdin; /*L04*/
			for (int charNdx = 0; charNdx < patternSize; charNdx++) {
				originalImage[charNdx][lineNdx] = line[charNdx];
			}//for
			for (int charNdx = 0; charNdx < patternSize; charNdx++) {
				newImage[charNdx][lineNdx] = line[charNdx + patternSize + 1];
			}//for
		}//for

		for (int transformationNdx = 0; transformationNdx 
			  < NUM_TRANSFORMATIONS; transformationNdx++) { /*L05*/
			isValidTransformation = true; /*L06*/
			
			
			for (int yNdx = 0; yNdx < patternSize; yNdx++) { /*L07*/
				for (int xNdx = 0; xNdx < patternSize; xNdx++) { /*L08*/
					originalValue = originalImage[xNdx][yNdx]; /*L09*/
					transformedXNdx = xNdx;
					transformedYNdx = yNdx;
					if (transformationMatrix[transformationNdx][2] == 1) { 
						/*L10*/
						transformedXNdx = yNdx; /*L11*/
						transformedYNdx = xNdx;
					}//if
					if (transformationMatrix[transformationNdx][0] == 1) { 
						/*L12*/
						transformedXNdx = patternSize - 1 - transformedXNdx; 
						/*L13*/
					}//if
					if (transformationMatrix[transformationNdx][1] == 1) { 
						/*L14*/
						transformedYNdx = patternSize - 1 - transformedYNdx; 
						/*L15*/
					}//if

					transformedValue = 
						newImage[transformedXNdx][transformedYNdx]; /*L16*/

					if (transformedValue != originalValue) { /*L17*/
						isValidTransformation = false; /*L18*/
						break;
					}//if
				}//for xNdx
				if (isValidTransformation == false) { /*L19*/
					break; /*L20*/
				}//if
			}//for yNdx
			if (isValidTransformation == true) { /*L21*/
				std::cout << "Pattern " << patternNum <<
					transformationMessage[transformationNdx] 
						<< std::endl; /*L22*/
				break; /*L23*/
			}//if
		}//for transformationNdx
		if (!isValidTransformation) {
			std::cout << "Pattern " << patternNum 
				<< transformationMessage[8] << std::endl;
		}//if
		patternNum = patternNum + 1; /*L24*/
		std::getline(std::cin, line);
	}//while
  //std::cout << std::endl;
	return 0; /*L25*/
}//main

//end mirrorBTL.cpp
