/********************************************************************************
|
|	Source code:  dateValidation.c
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
|
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
|	Description: 	This program takes in one parameter which indicates the
|			maximum number of valid dates the program will accept.
|			The program will then take in a stream of dates as input
|			and validate to see if the input is a valid date. The
|			program will continue to get input ontil the max number
|			of valid dates has been reached or an EOF is read. The
|			program will then output the valid dates.
|
|	Input:		Number of valid dates (at execution) and a series of
|			dates (while program is running)
|
|	Output:		The program will output all valid dates.
|
|	Process:	The program's steps are as follows:
|
|			1.  Validate or correct user input (terminate program if
|				validation is invalid).
|			2.  Take in dates ontil max number of valid dates or EOF
|			3.  Validates dates as inputed and updates valid dates
|				counter
|			4.  Output valid dates
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
#define NUM_CL_ARGS 2
#define CL_LOWER_BOUND 0
#define VALID_INPUT_INDEX 1

Bool validCLArgs(int, char**);

int main (int argc, char *argv[])
{

	Bool isEOF = FALSE;
	int maxValidInputs = EMPTY;
	int validInputs = 0;
	char validDate[MAX_CHARS_PER_LINE] = NO_STR;

	if (! validCLArgs(argc, argv))
	{
		return EXIT_FAILURE;
	}

	maxValidInputs = atoi(argv[VALID_INPUT_INDEX]);

	if (maxValidInputs == 0)
	{
		while (scanf("%s", validDate) != EOF)
		{
			if (validateDate(validDate))
			{
				printf("%s\n", validDate);
			}
		}
	}

	else
	{
		while (isEOF == FALSE && validInputs < maxValidInputs)
		{
			if(scanf("%s", validDate) == EOF)
			{
				isEOF = TRUE;
			}

			else if (validateDate(validDate))
			{
				printf("%s\n", validDate);
				validInputs++;
			}
		}
	}

	printf("%s", LAST_DATE_DELIVERED_STR);

	return EXIT_SUCCESS;
}

/***********************************validCLArgs*********************************
|
|	Function:	validCLArgs(int, char**);
|
|	Purpose:	Gets command line arguments and determines whether the
|			input is valid for this program. This function will
|			inform users of possible errors.
|
|	@author:	Kevin Gonzalez
|	@date:		April 3rd, 2018
|
|	@param:		int argc
|				Number of arguments passed through the command
|				line.
|
|	@param:		char **argv
|				Pointer to a character array containing the
|				arguments passed through the command line.
|
|	@return:	Bool valid
|				Returns TRUE if there is valid input. Returns
|				FALSE if user input is invalid.
|
*******************************************************************************/

Bool validCLArgs (int argc, char **argv)
{

	long validDates = EMPTY;
	int isNum = EMPTY;
	int temp = EMPTY;
	char remains = ' ';
	Bool valid = TRUE;

	validDates = atol(argv[VALID_INPUT_INDEX]);
	isNum = sscanf(argv[VALID_INPUT_INDEX], "%d%c", &temp, &remains);

	if(argc != NUM_CL_ARGS)
	{
		fputs("Invalid number of command line input.", ERRCHANNEL);
		valid = FALSE;
	}

	else if(validDates < 0 || validDates > INT_MAX || isNum != TRUE)
	{
		fputs("Invalid command line input.", ERRCHANNEL);
		valid = FALSE;
	}

	if (!valid)
	{
		fprintf(ERRCHANNEL, "The input must be a possitive interger "
			"(ranging from [ %d - %d ]).\n\n", CL_LOWER_BOUND,
			INT_MAX);
	}

	return valid;
}
