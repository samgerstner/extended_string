#ifndef EXTENDED_STRING_H
#define EXTENDED_STRING_H

    //Include Statements
    #include <math.h>
    #include <stdbool.h>

    //Function Stubs
    int compareStrings(const char *oneStr, const char *otherStr);
    void concatenateString(char *dest, const char *source);
    void copyString(char *dest, const char *source);
    bool findSubstring(const char *testStr, const char *searchStr);
    int getStringLength(const char *string);
    void getSubString(char *destStr, const char *sourceStr, int startIndex, int endIndex);
    void setStrToLowerCase(char *destStr, const char *sourceStr);
    char toLowerCase(char testChar);

#endif