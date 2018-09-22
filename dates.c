/********************************************************************************
|
|	Source code:  dates.c
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
|	Description: 	Contains functions to work with dates
|
|	Required
|	Features Not
|	Included:	dates.h
|
*******************************************************************************/

#include "dates.h"

// All define and prototypes local to source file
int findLastDay(Month, int);
char *monthStr[DEC + 1] = {"NO_MONTH", "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
				"JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

/********************************convertDate************************************
|
|	Function:	convertDate(char*);
|
|	Purpose:	Turns a string representing a date in format
|				month/day/year into format day month(String
|				abbreviation) year. If string was not in
|				correct format changes date to
|				LAST_DATE_DELIVERED_STR.
|
|	@author:	Kevin Gonzalez
|	@date:		April 3rd, 2018
|
|	@param:		char *date
|				String to be converted into format 2
|
********************************************************************************/

void convertDate(char *date)
{

	int day = EMPTY;
	Month month = NO_MONTH;
	long year = (long)INT_MIN - 1;
	int successfulScans = EMPTY;

	successfulScans = sscanf(date, "%d/%d/%ld", &month, &day, &year);
	if (successfulScans != DATE_ARGS)
	{
		sprintf(date, "%s", LAST_DATE_DELIVERED_STR);
	}

	else
	{
		sprintf(date, "%2u %s %d\n", day, monthStr[month], year);
	}

	return;
}

/**********************************findLastDay***********************************
|
|	Function:	findLastDay(Month, int);
|
|	Purpose:	Gets the max day for a given month and year.
|
|	@author:	Kevin Gonzalez
|	@date:		April 3rd, 2018
|
|	@param:		Month month
|
|	@param:		int year
|
|	@return:	int lastDay
|				Returns the last day of the month
|
*******************************************************************************/

int findLastDay(Month month, int year)
{
	int lastDay = EMPTY;

	if(month == FEB && (year % LEAP_YEAR_OCCURRENCE == 0))
	{
		lastDay = FEB_MAX_DAYS_LP;
	}

	else if(month == FEB)
	{
		lastDay = FEB_MAX_DAYS;
	}

	else if(((month < LAST_ODD_MONTH_WITH_31_DAYS) && (month % 2 == 0)) ||
		((month > LAST_ODD_MONTH_WITH_31_DAYS) && (month % 2 == 1)))
	{
		lastDay = MONTH_MAX_DAYS_30;
	}

	else
	{
		lastDay = MONTH_MAX_DAYS_31;
	}


	return lastDay;
}

/********************************validateDate***********************************
|
|	Function:	validateDate(char*);
|
|	Purpose:	Gets string and validates if it is in date format
|				month/day/year and whether month day and year
|				are valid integers (month [1-12], day [1-(28,
|				29, 30, or 31 depending on month and year)], and
|				year [INT_MIN - INT_MAX].
|
|	@author:	Kevin Gonzalez
|	@date:		April 3rd, 2018
|
|	@param:		char *dateStr
|				String to be tested for acurate date.
|
|	@return:	Bool valid
|				Returns TRUE if dateStr is a valid date. Returns
|				FALSE if dateStr is an invalid date.
|
********************************************************************************/

Bool validateDate(char dateStr[])
{

	int day = EMPTY;
	int month = NO_MONTH;
	long year = (long)INT_MIN - 1;
	int successfulScan = EMPTY;
	char remainder = ' ';
	Bool valid = TRUE;

	successfulScan = sscanf(dateStr, "%d/%d/%ld%c", &month, &day,
							&year, &remainder);

	if (successfulScan != DATE_ARGS)
	{
		valid = FALSE;
	}

	else if (year < INT_MIN || year > INT_MAX)
	{
		valid = FALSE;
	}

	else if (month <= NO_MONTH || month > DEC)
	{
		valid = FALSE;
	}

	else if (day <= 0 || day > findLastDay(month, year))
	{
		valid = FALSE;
	}

	return valid;
}
