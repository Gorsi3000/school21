#include "s21_string.h"
#include <string.h>
#include <stdio.h>
#define ASSERT(x, y) \
_Generic((x), size_t: assert_int, char*: assert_str, int: assert_int)(x, y)
#define SUCCESS printf("SUCCESS\t")
#define FAIL printf("FAIL\t\t")
#define TEST_STR "ABCDabcd"

void s21_strlen_test();

void assert_size_t(size_t f_rslt, size_t expected) {
    if (f_rslt == expected) SUCCESS;
    else FAIL;
    printf("in: %d\t\tout: %d\n", f_rslt, expected);
}
void assert_int(int f_rslt, int expected) {
    if (f_rslt == expected) SUCCESS;
    else FAIL;
    printf("in: %d\t\tout: %d\n", f_rslt, expected);
}
void assert_str(char* f_rslt, char* expected) {
    if (f_rslt == expected) SUCCESS;
    else FAIL;
    printf("in: %s\t\tout: %s\n", f_rslt, expected);
}

void s21_strlen_test() {
    char str1[] = {};
    char str2[] = {"1"};
    char str3[] = {""};
    char str4[] = {TEST_STR};

    ASSERT(s21_strlen(str1), 0);
    ASSERT(s21_strlen(str2), 1);
    ASSERT(s21_strlen(str3), 0);
    ASSERT(s21_strlen(str4), 8);
}