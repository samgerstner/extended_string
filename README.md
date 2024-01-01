# C Extended String Library

This project is intended to be used with the C programming language to extend the string.h library provided by the language. This library also provides implementations of many of the functions that are commonly used in the string.h library, all though it does not include all of them.

## Installing the Library

There are two different ways you can include this library in your project: manual installation & git sub-modules. Follow the instructions below for your preferred method.

**Manual Installation: **
1. Download the latest release package from [GitHub](https://github.com/samgerstner/extended_string/releases).
2. Extract the downloaded zip file using 7zip/unzip or a similar utility.
3. Copy the extracted extended_string folder into your project folder (usually in inc/).
4. Include the library in your .c file using `#include "../inc/extended_string/extended_string.h"` (This assumes your .c file is in the src/ directory and that the library folder was copied to inc/)

**Git Sub-Module: **
1. Follow [these instructions](https://github.blog/2016-02-01-working-with-submodules/) to add the sub-module to your project (Note: This assumes that you are using git version control in your project).
2. Include the library in your .c file using `#include "../inc/extended_string/src/extended_string.h"` (Replace the path to the .h file with the appropriate path for where your sub-module is installed)

## Documentation

An overview of the functions provided in this library is provided below. You can find the full project documentation [on my website](https://samgerstner.pro/docs/c-extended-string).

`int compareStrings(const char *leftStr, const char *rightStr);`
`char *concatenateString(const char *destStr, const char *sourceStr);`
`void copyString(char *destStr, const char *sourceStr);`
`int findSubString(const char *testStr, const char *searchStr);`
`int getStringLength(const char *testStr);`
`char *getSubString(const char *sourceStr, int startIndex, int endIndex);`
`char *stringToLowerCase(const char *sourceStr);`
`char charToLower(char testChar);`

## Credits

Documentation for this project was created with [Doxygen](https://www.doxygen.nl/).


## Licensing
This project is licensed under the GNU General Public License v3 (GNU GPLv3). See the license.txt file for the full license text.