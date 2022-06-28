#include "extended_string.h"

/**
 * @brief Compares two strings.
 * Compares two strings and returns an integer less than 0 if oneStr comes before otherStr, and an integer
 * greater than 0 if oneStr comes after otherStr, and 0 if oneStr is equal to otherStr.
 * 
 * @param oneStr The first string to compare.
 * @param otherStr The second string to compare.
 * 
 * @return int The integer differnece as described above.
 */
int compareStrings(const char *oneStr, const char *otherStr)
{
    //Initialize Method
    int oneLen = getStringLength(oneStr), otherLen = getStringLength(otherStr), index;

    for(index = 0; index < oneLen && index < otherLen; index++)
    {
        if(oneStr[index] < otherStr[index])
        {
            return oneStr[index] - otherStr[index];
        }
        else if(oneStr[index] > otherStr[index])
        {
            return otherStr[index] - oneStr[index];
        }
    }

    if(oneLen == otherLen)
    {
        return 0;
    }
    else
    {
        return abs(oneLen - otherLen);
    }
}

/**
 * @brief Concatenates source onto the end of destination.
 * Note: Assumes that destination is large enough to hold the result.
 * 
 * @param dest The string to concatenate onto.
 * @param source The string to concatenate.
 */
void concatenateString(char *dest, const char *source)
{
    //Initialize Method
    int destStartingLen = getStringLength(dest), sourceLen = getStringLength(source), index;

    for(index = 0; index < sourceLen; index++)
    {
        dest[destStartingLen + index] = source[index];
    }

    dest[destStartingLen + sourceLen] = '\0';
}

/**
 * @brief Copies the contents of the source string to the destination string.
 * Note: Assumes that the destination string is large enough to hold the source string.
 * 
 * @param dest The string to copy into.
 * @param source The string to copy from.
 */
void copyString(char *dest, const char *source)
{
    //Initialize Method
    int index = 0;

    while(index < getStringLength(source))
    {
        dest[index] = source[index];
        index++;
    }

    dest[index] = '\0';
}

/**
 * @brief Tests if a substring is contained within a string.
 * 
 * @param testStr The substring to locate.
 * @param searchStr The string to search for the substring in.
 *  
 * @return bool True if the substring is contained within the string, false otherwise. 
 */
bool findSubstring(const char *testStr, const char *searchStr)
{
    //Initialize Method
    int testLen = getStringLength(testStr), searchLen = getStringLength(searchStr), consecutiveMatches = 0, index, testIndex = 0;

    for(index = 0; index < testLen; index++)
    {
        if(searchStr[index] == testStr[testIndex])
        {
            consecutiveMatches++;
            if(consecutiveMatches == searchLen)
            {
                return true;
            }
        }
        else
        {
            consecutiveMatches = 0;
            testIndex = 0;
        }
    }
}

/**
 * @brief Finds the length of a string.
 * 
 * @param string The string to find the length of.
 * 
 * @return int The length of the string.
 */
int getStringLength(const char *string)
{
    //Initialize Method
    int length = 0, index = 0;

    while(string[index] != '\0')
    {
        length++;
        index++;
    }

    return length;
}

/**
 * @brief Gets the sub string from startIndex to endIndex inclusive.
 * 
 * @param destStr The string to copy the sub string into.
 * @param sourceStr The string to copy the sub string from.
 * @param startIndex The index to start copying from.
 * @param endIndex The index to stop copying at.
 */
void getSubString(char *destStr, const char *sourceStr, int startIndex, int endIndex)
{
    //Initialize Method
    int index = 0;

    while(index < endIndex - startIndex)
    {
        destStr[index] = sourceStr[startIndex + index];
        index++;
    }

    destStr[index] = '\0';
}

void setStrToLowerCase(char *destStr, const char *sourceStr)
{
    //Initialize Method
    int index = 0;

    while(sourceStr[index] != '\0')
    {
        destStr[index] = toLowerCase(sourceStr[index]);
        index++;
    }

    destStr[index] = '\0';
}

/**
 * @brief Converts a charcter to lower case (if needed).
 * 
 * @param testChar The character to convert to lower case.
 * 
 * @return char The character concerted to lowercase, or unchanged ifalready lowercase.
 */
char toLowerCase(char testChar)
{
    //Initialize Method
    if(testChar >= 'A' && testChar <= 'Z')
    {
        return testChar + 32;
    }
    
    return testChar;
}