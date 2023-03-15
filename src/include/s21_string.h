#include <stdlib.h>
#ifndef S21_STRING
#define S21_STRING

size_t s21_strlen(const char* str);
int   s21_strcmp(char *s1, char *s2);
char* s21_strcpy(char *dest, const char *src);
char* s21_strcat(char *dest, const char *src);
char* s21_strchr(const char* str, int);
char* s21_strstr(const char* str, const char* to_find);
char* s21_strtok(char* str, const char* delimiters );
#endif