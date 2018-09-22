#	Makefile
#	Author:  Kevin Gonzalez
#	Student ID:  5702392
#	Assignment:  Program #5 - Date Converter
#	Course:  COP 4338 (Programming III)
#	Section:  U01
#	Instructor:  William Feild
#	Due Date:  April 3rd, 2018, class time
#
#	I hereby certify that this collective work is my own
#	and none of it is the work of any other person or entity.
#	______Kevin_Gonzalez_______________ [Signature]
#


VALIDATEDATES = dateValidation.c dates.c
VALIDDATESOUT = validDates.out
DATECONVERTER = dateConverter.c dates.c
CONVERTEROUT = convertDates.out

build:
	make buildDateValidation
	make buildDateConverter

testDateValidationManual: $(VALIDDATESOUT)
# ! should ignore errors
	make buildDateValidation
	! ./$(VALIDDATESOUT) -10
	! ./$(VALIDDATESOUT) 9999999999999999999999999999999999999999
	! ./$(VALIDDATESOUT) Hi:D
	! ./$(VALIDDATESOUT) Hello There
	./$(VALIDDATESOUT) 3
	./$(VALIDDATESOUT) 0
	./$(VALIDDATESOUT) 5

buildDateValidation: $(VALIDATEDATES)
	gcc $(VALIDATEDATES) -o $(VALIDDATESOUT)

buildDateConverter: $(DATECONVERTER)
	gcc $(DATECONVERTER) -o $(CONVERTEROUT)
