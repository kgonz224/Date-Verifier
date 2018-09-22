/********************************************************************************
|
|	Source code:  dates.h
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
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define ERRCHANNEL stderr

#define EMPTY -1
#define NO_STR "No String"
#define DATE_ARGS 3
#define MAX_CHARS_PER_LINE 80

#define LEAP_YEAR_OCCURRENCE 4

#define FEB_MAX_DAYS 28
#define FEB_MAX_DAYS_LP 29
#define MONTH_MAX_DAYS_30 30
#define MONTH_MAX_DAYS_31 31

#define LAST_ODD_MONTH_WITH_31_DAYS 7

#define LAST_DATE_DELIVERED_STR ":D"

typedef enum Boolean {FALSE, TRUE} Bool;

typedef enum Month {NO_MONTH, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT,
								NOV, DEC} Month;

//Prototypes defined in dates.c
void convertDate(char*);
Bool validateDate(char*);
