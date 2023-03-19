#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math_func.h"
#include "lexema.h"
#define SIZE 1001

int _isdigit(const char c);
void init_lexem(double value, lexema_type type, lexema **lex, int index);


lexema ** input(void) {
    char *string;
    lexema **lex = (lexema **)malloc(sizeof(lexema *));
    string = (char *)malloc(sizeof(char) * SIZE);
    if (string == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    fgets(string, SIZE, stdin);
    char ch;
    int flag = 0;
    int i = 0;
    int index_lexema = 0;
    int n_index = 0;
    char number[10];
    while ((ch = string[i++]) != '\0') {
        while (_isdigit(ch)) {
            number[n_index++] = ch;
            ch = string[i++];
            flag = 1;
        }
        if (flag) {
            double digit = atof(number);
            init_lexem(digit, operand, lex, index_lexema);
            lex[index_lexema]->one_param = NULL;
            lex[index_lexema]->two_param = NULL;
            index_lexema++;
            flag = 0;
        }

        if (ch == 's') {
            if (string[i] == 'i') {
                init_lexem(0, sinus, lex, index_lexema);
                lex[index_lexema]->one_param = sin;
                lex[index_lexema]->two_param = NULL;
                i += 2;
                index_lexema++;
            }
            else {
                init_lexem(0, sqrt_l, lex, index_lexema);
                lex[index_lexema]->one_param = sqrt;
                lex[index_lexema]->two_param = NULL;
                i += 3;
                index_lexema++;
            }
        }
        if (ch == 'l') {
            init_lexem(0, log_e, lex, index_lexema);
            lex[index_lexema]->one_param = log;
            lex[index_lexema]->two_param = NULL;
            i += 3;
            index_lexema++;
        }
        if (ch == 'c') {
            char ch2 = string[i];
            if (ch2 == 'o') {
                init_lexem(0, cosinus, lex, index_lexema);
                lex[index_lexema]->one_param = cos;
                lex[index_lexema]->two_param = NULL;
                index_lexema++;
                i += 2;
            }
            else {
                init_lexem(0, cotangens, lex, index_lexema);
                lex[index_lexema]->one_param = ctg;
                lex[index_lexema]->two_param = NULL;
                i += 2;
                index_lexema++;
            }
        }
        if (ch == 't') {
            init_lexem(0, tangens, lex, index_lexema);
            lex[index_lexema]->one_param = tan;
            lex[index_lexema]->two_param = NULL;
            i++;
            index_lexema++;
        }
        if (ch == '(') {
            init_lexem(0, bracket_open, lex, index_lexema);
            lex[index_lexema]->one_param = NULL;
            lex[index_lexema]->two_param = NULL;
            index_lexema++;
        }
        if (ch == ')') {
            init_lexem(0, bracket_close, lex, index_lexema);
            lex[index_lexema]->one_param = NULL;
            lex[index_lexema]->two_param = NULL;
            index_lexema++;
        }
        if (ch == '+') {
            init_lexem(0, plus, lex, index_lexema);
            lex[index_lexema]->one_param = NULL;
            lex[index_lexema]->two_param = sum;
            index_lexema++;
        }
        if (ch == '-') {
            if (_isdigit(string[i-1])) {
                init_lexem(0, min_binary, lex, index_lexema);
                lex[index_lexema]->one_param = NULL;
                lex[index_lexema]->two_param = binary_minus;
                index_lexema++;
            } else {
                init_lexem(0, min_unary, lex, index_lexema);
                lex[index_lexema]->one_param = unary_minus;
                lex[index_lexema]->two_param = NULL;
                index_lexema++;
            }
        }
        if (ch == '*') {
            init_lexem(0, mul, lex, index_lexema);
            lex[index_lexema]->one_param = NULL;
            lex[index_lexema]->two_param = multiply;
            index_lexema++;
        }
        if (ch == '/') {
            init_lexem(0, division, lex, index_lexema);
            lex[index_lexema]->one_param = NULL;
            lex[index_lexema]->two_param = _division;
            index_lexema++;
        }
        if (ch == 'x') {
            init_lexem(0, X, lex, index_lexema);
            lex[index_lexema]->one_param = NULL;
            lex[index_lexema]->two_param = NULL;
            index_lexema++;
        }
    }
    //TODO last lexem
    free(string);
    return lex;
}

void init_lexem(double value, lexema_type type, lexema **lex, int index) {
    lex[index] = (lexema *)malloc(sizeof(lexema));
    if (lex[index] == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    lex[index]->value = value;
    lex[index]->type = type;

}

int _isdigit(const char c) {
    int symbol = c - '0';
    if (0 <= symbol && symbol <= 9)
        return 1;
    return 0;
}
