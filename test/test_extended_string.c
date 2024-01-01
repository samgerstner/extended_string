#include "../inc/unity/unity.h"
#include "../src/extended_string.h"

void testCompareStrings(void)
{
    TEST_ASSERT_EQUAL_INT(0, compareStrings("string", "string"));
    TEST_ASSERT_EQUAL_INT(-1, compareStrings("string1", "string2"));
    TEST_ASSERT_EQUAL_INT(-32, compareStrings("ABC", "abc"));
    TEST_ASSERT_EQUAL_INT(1, compareStrings("abcd", "abc"));
}

void testConcatenateString(void)
{
    TEST_ASSERT_EQUAL_STRING("abcd", concatenateString("ab", "cd"));
    TEST_ASSERT_EQUAL_STRING("Hello, World!", concatenateString("Hello, ", "World!"));
    TEST_ASSERT_EQUAL_STRING("stringstring", concatenateString("string", "string"));
    TEST_ASSERT_EQUAL_STRING("test string", concatenateString("test ", "string"));
}

void testCopyString(void)
{
    char *dest1 = (char*) malloc(5);
    char *dest2 = (char*) malloc(6);
    char *dest3 = (char*) malloc(6);
    char *dest4 = (char*) malloc(6);

    copyString(dest1, "test");
    copyString(dest2, "test1");
    copyString(dest3, "test2");
    copyString(dest4, "test3");
    
    TEST_ASSERT_EQUAL_STRING("test", dest1);
    TEST_ASSERT_EQUAL_STRING("test1", dest2);
    TEST_ASSERT_EQUAL_STRING("test2", dest3);
    TEST_ASSERT_EQUAL_STRING("test3", dest4);
}

void testFindSubString(void)
{
    TEST_ASSERT_EQUAL_INT(0, findSubString("abcdefg", "abc"));
    TEST_ASSERT_EQUAL_INT(3, findSubString("abcdefg", "de"));
    TEST_ASSERT_EQUAL_INT(5, findSubString("abcdefg", "fg"));
    TEST_ASSERT_EQUAL_INT(-1, findSubString("abcdefg", "lm"));
}

void testGetStringLength(void)
{
    TEST_ASSERT_EQUAL_INT(4, getStringLength("test"));
    TEST_ASSERT_EQUAL_INT(6, getStringLength("string"));
    TEST_ASSERT_EQUAL_INT(9, getStringLength("123456789"));
    TEST_ASSERT_EQUAL_INT(7, getStringLength("someval"));
}

void testGetSubString(void)
{
    TEST_ASSERT_EQUAL_STRING("Hello", getSubString("Hello, World!", 0, 4));
    TEST_ASSERT_EQUAL_STRING("World", getSubString("Hello, World!", 7, 11));
    TEST_ASSERT_EQUAL_STRING("abc", getSubString("abcdefg", 0, 2));
    TEST_ASSERT_EQUAL_STRING("def", getSubString("abcdefg", 3, 5));
}

void testStringToLowerCase(void)
{
    TEST_ASSERT_EQUAL_STRING("abcdefg", stringToLowerCase("ABCDEFG"));
    TEST_ASSERT_EQUAL_STRING("abcdefg", stringToLowerCase("abcdefg"));
    TEST_ASSERT_EQUAL_STRING("abc123", stringToLowerCase("ABC123"));
    TEST_ASSERT_EQUAL_STRING("!*?&#@^$", stringToLowerCase("!*?&#@^$"));
}

void testCharToLower(void)
{
    TEST_ASSERT_EQUAL_CHAR('n', charToLower('N'));
    TEST_ASSERT_EQUAL_CHAR('n', charToLower('n'));
    TEST_ASSERT_EQUAL_CHAR('!', charToLower('!'));
    TEST_ASSERT_EQUAL_CHAR('1', charToLower('1'));
}

void setUp(void) {}

void tearDown(void) {}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(testCompareStrings);
    RUN_TEST(testConcatenateString);
    RUN_TEST(testCopyString);
    RUN_TEST(testFindSubString);
    RUN_TEST(testGetStringLength);
    RUN_TEST(testGetSubString);
    RUN_TEST(testStringToLowerCase);
    RUN_TEST(testCharToLower);
    return UNITY_END();
}