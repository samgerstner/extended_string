#include "extended_string.h"

/**
 * Compares two strings and returns an integer value based on the comparison.
 * 
 * Compares two strings with the following results:
 *      If left string less than right string, returns less than zero
 *      If left string greater than right string, return greater than zero
 *      If left string equals right string, returns zero (equals test includes length)
 * 
 * @param leftStr The first of two strings to compare.
 * @param rightStr The second of two strings to compare.
 * 
 * @return int Integer result of comparison as specified.
 */
int compareStrings(const char *leftStr, const char *rightStr)
{
    //Initialize Function
    int diff, index = 0;

    //loop to end of shortest string
    while(leftStr[index] != NULL_CHAR && rightStr[index] != NULL_CHAR && index < MAX_STR_LEN)
    {
        //get differnce in character ASCII values
        diff = leftStr[index] - rightStr[index];

        //check for difference
        if(diff != 0)
        {
            return diff;
        }

        //increment index
        index++;
    }

    //return difference in length, if any
    return getStringLength(leftStr) - getStringLength(rightStr);
}

/**
 * Appends one string onto the end of another.
 * 
 * @param destStr The string to appended onto.
 * @param sourceStr The string to be appended.
 * 
 * @return char* The concatenated string.
 */
char *concatenateString(const char *destStr, const char *sourceStr)
{
    //Initialize Method
    int destStrLen = getStringLength(destStr);
    int sourceStrLen = getStringLength(sourceStr);
    char *result = (char*) malloc(sizeof(sourceStrLen + destStrLen + 1));

    //Copy destination string into result
    copyString(result, destStr);

    //Append sourceStr to destStr
    int resultIndex = destStrLen;
    int sourceIndex = 0;
    while(sourceStr[sourceIndex] != NULL_CHAR && resultIndex < MAX_STR_LEN)
    {
        //Copy character at sourceIndex
        result[resultIndex] = sourceStr[sourceIndex];

        resultIndex++;
        sourceIndex++;
    }

    return result;
}

/**
 * Copies one string into another, overwriting data in the destination string.
 * 
 * @param destStr The string that will be copied into.
 * @param sourceStr The string to copy from.
 */
void copyString(char *destStr, const char *sourceStr)
{
    //Initialize Method
    int index = 0;

    //check for source and destination not the same (aliasing, compare pointers)
	if(destStr != sourceStr)
    {
        while(sourceStr[index] != NULL_CHAR && index < MAX_STR_LEN)
		{
			//assign characters to end of dest string
			destStr[index] = sourceStr[index];

			//update index
			index++;

			//set temp end of dest string
			destStr[index] = NULL_CHAR;
		}
    }
}

/**
 * Linear search for given substring within another string.
 * 
 * @param testStr The string that will be scanned for the sub-string.
 * @param searchStr The sub-string to search for.
 * 
 * @return int Index of the substring, or -1 if not found.
 */
int findSubString(const char *testStr, const char *searchStr)
{
    //Initialize Function
    int testStrLen = getStringLength(testStr);
    int masterIndex = 0;
    int searchIndex, internalIndex;

    //loop accross test string
    while(masterIndex < testStrLen)
    {
        //Set internal loop index to current test string index
		internalIndex = masterIndex;

        //set internal search index to zero
		searchIndex = 0;

        //loop to end of test string while test string/sub string characters are the same
		while(internalIndex <= testStrLen && testStr[internalIndex] == searchStr[searchIndex])
        {
            //increment test string, substring indicies
			internalIndex++;
			searchIndex++;

            //check for end of substring (search completed)
			if(searchStr[searchIndex] == NULL_CHAR)
			{
				//return beginning location of sub string
				return masterIndex;
			}
        }

        masterIndex++;
    }

    //substring was not found
    return -1;
}

/**
 * Gets string length.
 * 
 * @param testStr String to get the length of.
 * 
 * @return int Length of string.
 */
int getStringLength(const char *testStr)
{
    int index = 0;

	while(index < STD_STR_LEN && testStr[index] != NULL_CHAR)
	{
		index++;
	}

	return index;
}

/**
 * Returns sub-string between specified indices.
 * 
 * Returns a sub-string of sourceStr between startIndex and endIndex, inclusive. If an invalid index combination is provided, returns NULL.
 * 
 * @param sourceStr The string that you want to take a sub-string of.
 * @param startIndex Starting index of sub-string.
 * @param endIndex Ending index of sub-string.
 * 
 * @return string The sub-string as specified.
 */
char *getSubString(const char *sourceStr, int startIndex, int endIndex)
{
    //Initialize Method
    int sourceLength = getStringLength(sourceStr);
    int destIndex = 0;
    int sourceIndex = startIndex;
    char *result;

    //Check for indices within limits
    if(startIndex >= 0 && startIndex <= endIndex && endIndex < sourceLength)
    {
        //Create result string
        result = (char*) malloc((endIndex - startIndex) + 2);

        //loop accross requsted substring (indicies)
		while(sourceIndex <= endIndex)
        {
            result[destIndex] = sourceStr[sourceIndex];

            destIndex++;
			sourceIndex++;

            result[destIndex] = NULL_CHAR;
        }

        return result;
    }

    return NULL;
}

/**
 * Converts a string to all lower-case letters.
 * 
 * @param sourceStr String to convert to lower-case.
 * 
 * @return string All lower-case version of sourceStr.
 */
char *stringToLowerCase(const char *sourceStr)
{
    //Initialize Method
    int sourceStrLen = getStringLength(sourceStr);
    char *result = (char*) malloc(sourceStrLen + 1);
    int index = 0;

    //Copy sourceStr into result
    copyString(result, sourceStr);

    //loop accross source string
	while(sourceStr[index] != NULL_CHAR && index < MAX_STR_LEN)
    {
        result[index] = charToLower(sourceStr[index]);
        index++;
        result[index] = NULL_CHAR;
    }

    return result;
}

/**
 * Converts character to lower case (if it is a letter).
 * 
 * @param testChar Character to conert to lower case.
 * 
 * @return char Lower case character if character was upper case, un-modified character otherwise.
 */
char charToLower(char testChar)
{
    if(testChar >= 'A' && testChar <= 'Z')
	{
		//convert to lower case
		return testChar - 'A' + 'a';
	}

    return testChar;
}