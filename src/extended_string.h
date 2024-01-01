#ifndef EXTENDED_STRING_H
#define EXTENDED_STRING_H

    //Include Statements
    #include <stdio.h>
    #include <stdlib.h>

    //Constant Definitions
    #define NULL_CHAR '\0'
    #define SPACE_CHAR ' '
    #define NON_PRINTABLE_CHAR (char)127
    #define COMMA ','
    #define COLON ':'
    #define PERIOD '.'
    #define SEMICOLON ';'
    #define MIN_STR_LEN 2
    #define MAX_STR_LEN 2048
    #define STD_STR_LEN 64

    //Enum Definitions
    typedef enum
    {
        NO_ERROR,
        INVALID_FILE_NAME,
        INPUT_BUFFER_OVERLOAD
    } StringManipulationCode;

    //Function Stubs
    int compareStrings(const char *leftStr, const char *rightStr);
    char *concatenateString(const char *destStr, const char *sourceStr);
    void copyString(char *destStr, const char *sourceStr);
    int findSubString(const char *testStr, const char *searchStr);
    int getStringLength(const char *testStr);
    char *getSubString(const char *sourceStr, int startIndex, int endIndex);
    char *stringToLowerCase(const char *sourceStr);
    char charToLower(char testChar);

    /*
        TODO: Implement Version 1.1 Functions

        StringManipCode getStringConstrained(FILE *inStream, Boolean clearLeadingNonPrintable, Boolean clearLeadingSpace, 
	        Boolean stopAtNonPrintable, char delimeter, char *capturedString);
        StringManipCode getStringToDelimeter(FILE *inStream, char delimeter, char *capturedString);
        StringManipCode getStringToLineEnd(FILE *inStream, char *capturedString);    
    */

#endif