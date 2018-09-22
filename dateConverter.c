/********************************************************************************
|
|	Source code:  dateConverter.c
|	Author:  Kevin Gonzalez
|	Student ID:  5702392
|	Assignment:  Program #5 - Date Converter
|
|	Course:  COP 4338 (Programming III)
|	Section:  U01
|	Instructor:  William Feild
|	Due Date:  April 3rd, 2018, class time
|
|	I hereby certify that this collective work is my own
|	and none of it is the work of any other person or entity.
|	______Kevin_Gonzalez_______________ [Signature]
|
|	Language:  C
|	Compile/Run:
| 		gcc dateValidation.c dates.c -o validDates.out
|		gcc dateConverter.c dates.c -o convertDates.out
|
| 		./validDates.out < dates.dat validDates |
|					./convertDates.out > output.dat
|
|			//validDates is an integer representing the  max number
|				of valid dates the program will accept.
|				0 will find all valid dates from file
|			//dates.dat is a file of information that should contain
|				possible dates.
|
|	************************************************************************
|
|	Description: 	This program takes in valid dates in month/day/year
|			format, convert it into a day month(string abbreviation)
|			 year format and write it into a file (output.dat).
|
|	Input:		A series of valid dates. The string ":D" lets the program
|			know that all the valid dates have been inputed.
|
|	Output:		The program will output all valid dates in day month
|			(string abbreviation) year format into a file called
|			output.dat.
|
|	Process:	The program's steps are as follows:
|
|			1.  Ask for dates until LAST_DATE_DELIVERED_STR (":D")
|			2.  Convert dates inputed to new format
|			3.  Write new date format in output.dat
|			4.  Open original file (dates.dat)
|			5.  Print its content
|			6.  Close file
|
|	Required
|	Features Not
|	Included:	dates.h
|
|	Known Bugs:  None; the program operates correctly.
|
*******************************************************************************/

#include "dates.h"

// All define and prototypes local to source file
#define READ "r"
#define ORIGINALFILE "dates.dat"

void printFileContent(char*);

int main ()
{
	char date[MAX_CHARS_PER_LINE] = NO_STR;

	while (strcmp(date, LAST_DATE_DELIVERED_STR) != 0)
	{
		scanf("%s", date);
		convertDate(date);
		if (strcmp(date, LAST_DATE_DELIVERED_STR) != 0)
		{
			printf("%s", date);
		}
	}

	puts("");
	printFileContent(ORIGINALFILE);

	return EXIT_SUCCESS;
}

/******************************printFileContent*********************************
|
|	Function:	printFileContent(char*);
|
|	Purpose:	Opens a file and prints its content. If file not found
|			then prints a file not read message.
|
|	@author:	Kevin Gonzalez
|	@date:		April 3rd, 2018
|
|	@param:		char *fileName
|				A string representing a readable file name or
|				address from current directory.
|
*******************************************************************************/


void printFileContent(char *fileName)
{

	FILE *filePtr = NULL;
	filePtr = fopen(fileName, READ);

	if (filePtr == NULL)
	{
		fprintf(ERRCHANNEL, "Original File, \"%s\", could not be read "
			"from.\n", fileName);
	}

	else
	{
		char line[MAX_CHARS_PER_LINE] = NO_STR;

		while (!feof(filePtr))
		{
			fscanf(filePtr, "%s\n", line);
			printf("%s\n", line);
		}

		fclose(filePtr);
	}

	return;
}
