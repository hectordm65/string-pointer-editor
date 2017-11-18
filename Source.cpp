/*Name: Hector Dominguez-Maceda
Class: CSC 2430
Date: 4/23/2016
Assignment: Lab 4
Description: This program opens a file and moves string around
*/

#include <iostream>
#include <fstream>

using namespace std;

#include "\\myhome.spu.edu\users\dominguezmah\Documents\Visual Studio 2013\Projects\2 good\Lab 4, string editor\Lab 4\stringPkg.h"

const int STRING_MAX = 256;

int main()
{
	system("cls");	//clears the screen

	ifstream in("Inventory.csv");	//Opens the inventory file

	if (in.fail())	//if it fails, it will output that the file failed to open
	{
		cout << "Unable to open file." << endl;
		exit(1);
	}

	//Outputs a message to tell the user what this program is going to do
	cout << "Inventory Status Report, produced by Hector Dominguez-Maceda" << endl;

	char input[STRING_MAX];			//Here is where the file will reside
	char LineAfter[STRING_MAX];		//this is used to compare each line so that it can determine to output the department name or not
	char EditedLine[STRING_MAX];	//holds the edited line that doesn't contain the department name, then gets rid of the inventory tag, and then gets rid of the quantity on hand
	char InventoryTag[STRING_MAX];	//holds the inventory tag
	char Quantity[STRING_MAX];		//holds the quantity for each item
	char Department[STRING_MAX];	//holds the department
	int CommaFinder = 0;			//holds a value for the position of the comma
	int CompareVal = 0;				//holds the "truth value" of the comparison of strings
	int LineLength = 0;				//holds the line length of each line
	int QuantityInt = 0;			//holds integer of quantity
	int TotalInventory = 0;			//holds the total of the quantity

	while (!in.eof())
	{
		in.getline(input, STRING_MAX);	//The file is being loaded into this string, line by line

		CommaFinder = stringFindchar(input, ',', 0);	//locates the comma position

		stringCopy(Department, CommaFinder + 1, input);	//uses the comma position to determine how much to copy (it is plus 1 to hold the extra \0 character

		LineLength = stringLength(input);	//gives a length of the line

		CompareVal = stringCompare(input, LineAfter);	//compares each line to determine if the department needs to be outputted
		
		if (CompareVal != 0)	//will output everything only if the lines are not equal to each other
		{
			cout << "Department: " << Department << endl;
		}

		stringSubstring(EditedLine, LineLength, input, CommaFinder + 1, LineLength - CommaFinder);

		CommaFinder = stringFindchar(EditedLine, ',', 0);

		stringCopy(InventoryTag, CommaFinder + 1, EditedLine);	//copies inventory tag from EditedLine

		stringSubstring(EditedLine, LineLength, EditedLine, CommaFinder + 1, LineLength - CommaFinder);

		CommaFinder = stringFindchar(EditedLine, ',', 0);	//finds the location of the comma

		stringCopy(Quantity, CommaFinder + 1, EditedLine);	//copies the quantity from Editedline, and stops at the position of the comma

		stringSubstring(EditedLine, LineLength, EditedLine, CommaFinder + 1, LineLength - CommaFinder);

		CommaFinder = stringFindchar(EditedLine, ',', 0);

		cout << "\t" << EditedLine << " (" << InventoryTag << "): " << Quantity << endl;	//outputs lines that are edited

		QuantityInt = stringConvertToInt(Quantity);	//converts each quantity char into an int

		TotalInventory = TotalInventory + QuantityInt;	//holds the total inventory

		stringCopy(LineAfter, STRING_MAX, input);	//gives the computer something to compare
	}

	cout << "\nTotal Items in inventory: " << TotalInventory << endl;

	return (0);
}