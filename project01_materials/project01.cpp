// ****************************************
// Program Title: Project 1
// Project File: project01.cpp
// Name: Jaiden Gann
// Course Section: CPE-212-01
// Due Date: 09/22/21
// Program description: Function definitions
// to perform various tasks on "images" 
// (i.e Image Manipulation) 
// Score: 100
// ****************************************

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void LoadImage(const string imagefile, int image[MAXROWS][MAXCOLS])
{
	ifstream infile;
	infile.open(imagefile.c_str());	//open filestream
	
	infile.ignore( 100, '\n');	//ignore header
	infile.ignore( 100, '\n');	//ignore empty line

	//put data into image array
	for (int row = 0; row < MAXROWS; row++)
	{
		for (int col = 0; col < MAXCOLS; col++)
		{
			infile >> image[row][col];
		}
	}
	infile.clear();	//clear file stream
	infile.close();	//close file stream
}
void FlipHorizontal(int image[MAXROWS][MAXCOLS])
{
	//horizontal = rows not changing
	int tempImage;
	for (int row = 0; row < MAXROWS; row++)
	{
		for (int col = 0; col < MAXCOLS/2; col++) // divide by 2 to split array
		{
			tempImage = image[row][col];		//holds original value of array
			image[row][col] = image[row][9 - col];		//performs flip
			image[row][9 - col] = tempImage;		//places original values back into flipped array
		}
	}
}
void FlipVertical(int image[MAXROWS][MAXCOLS])
{
	//vertical = columns not changing
	int tempImage;
	for (int row = 0; row < MAXROWS /2; row++)	//divide by two to split the array
	{
		for (int col = 0; col < MAXCOLS; col++)
		{
			tempImage = image[row][col];		//holds original value of array
			image[row][col] = image[9 - row][col];		//performs the flip
			image[9 - row][col] = tempImage;		//places original values back into flipped array
		}
	}
}
void RotateCW(int image[MAXROWS][MAXCOLS])
{
	int tempImage;
	//transpose
	for (int row = 0; row < MAXROWS; row++)
	{
		for (int col = row + 1; col < MAXCOLS; col++)
		{
			tempImage = image[row][col];
			image[row][col] = image[col][row];
			image[col][row] = tempImage;

		}
	}
	//flip it horizontally
	for (int row = 0; row < MAXROWS; row++)
	{
		for (int col = 0; col < MAXCOLS / 2; col++)
		{
			tempImage = image[row][col];
			image[row][col] = image[row][9 - col];	
			image[row][9 - col] = tempImage;
		}
	}
}
void RotateCCW(int image[MAXROWS][MAXCOLS])
{
	int tempImage;
	//transpose
	for (int row = 0; row < MAXROWS; row++)
	{
		for (int col = row + 1; col < MAXCOLS; col++)
		{
			tempImage = image[row][col];
			image[row][col] = image[col][row];
			image[col][row] = tempImage;

		}
	}
	//flip it vertically
	for (int row = 0; row < MAXROWS / 2; row++)
	{
		for (int col = 0; col < MAXCOLS; col++)
		{
			tempImage = image[row][col];
			image[row][col] = image[9 - row][col];	
			image[9 - row][col] = tempImage;
		}
	}
}
void Transpose(int image[MAXROWS][MAXCOLS])
{
	int tempImage;
	for (int row = 0; row < MAXROWS; row++)
	{
		for (int col = row + 1; col < MAXCOLS; col++)
		{
			tempImage = image[row][col]; //holds original value of array
			image[row][col] = image[col][row];	//perfroms the operation on the array
			//image is now equal to changed image array
			image[col][row] = tempImage;	//places the original values back into changed array
		}
	}
}
