#include "print_module.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char print_char(char ch) {
    printf("%c", ch);
    return ch;
}

void print_log(char (*print)(char), char* message) {
    char timeString[9];
    const time_t timer = time(NULL);
    struct tm* time_info = localtime(&timer);
    strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);

    printf("%s\t", Log_prefix);
    int i = 0;
    while (timeString[i]) (*print)(timeString[i++]);
    printf("\t%s", message);
}