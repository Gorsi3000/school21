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
    printf("%s\n", string);
    while (string[i] != '\0') {
        ch = string[i];
        printf("%d: %c %d\n", i, ch, index_lexema);
        while (_isdigit(ch)) {
            number[n_index++] = ch;
            ch = string[i++];
            flag = 1;
            printf("YE TUT \n");
        }
        if (flag) {
            printf("NUMBER ");
            double digit = atof(number);
            init_lexem(digit, operand, lex, index_lexema);
            printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
            index_lexema++;
            flag = 0;
        }

        if (ch == 's') {
            printf("______%c_______\n", string[i+1]);
            if (string[i+1] == 'i') {
                printf("SINUS ");
                init_lexem(0, sinus, lex, index_lexema);
                printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
                lex[index_lexema]->one_param = sin;
                i += 2;
                index_lexema++;
            }
            else {
                printf("SQRT ");
                init_lexem(0, sqrt_l, lex, index_lexema);
                printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
                lex[index_lexema]->one_param = sqrt;
                i += 2;
                index_lexema++;
            }
        }
        if (ch == 'l') {
            printf("LOG ");
            init_lexem(0, log_e, lex, index_lexema);
            printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
            lex[index_lexema]->one_param = log;
            i += 3;
            index_lexema++;
        }
        if (ch == 'c') {
            char ch2 = string[i];
            if (ch2 == 'o') {
                printf("COSINUS ");
                init_lexem(0, cosinus, lex, index_lexema);
                printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
                lex[index_lexema]->one_param = cos;
                index_lexema++;
                i += 2;
            }
            else {
                printf("COTANGENS ");
                init_lexem(0, cotangens, lex, index_lexema);
                printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
                lex[index_lexema]->one_param = ctg;
                i += 1;
                index_lexema++;
            }
        }
        if (ch == 't') {
            printf("TANGENS ");
            init_lexem(0, tangens, lex, index_lexema);
            printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
            lex[index_lexema]->one_param = tan;
            i++;
            index_lexema++;
        }
        if (ch == '(') {
            printf("BRACKET_OPEN ");
            init_lexem(0, bracket_open, lex, index_lexema);
            printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
            index_lexema++;
        }
        if (ch == ')') {
            printf("BRACKET CLOSE ");
            init_lexem(0, bracket_close, lex, index_lexema);
            printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
            index_lexema++;
        }
        if (ch == '+') {
            printf("PLUS ");
            init_lexem(0, plus, lex, index_lexema);
            printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
            lex[index_lexema]->two_param = sum;
            index_lexema++;
        }
        if (ch == '-') {
            if (_isdigit(string[i-1])) {
                printf("BINARY MIN ");
                init_lexem(0, min_binary, lex, index_lexema);
                printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
                lex[index_lexema]->two_param = binary_minus;
                index_lexema++;
            } else {
                printf("UNARNIY MIN ");
                init_lexem(0, min_unary, lex, index_lexema);
                printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
                lex[index_lexema]->one_param = unary_minus;
                index_lexema++;
            }
        }
        if (ch == '*') {
            printf("ZVEZDO4ka ");
            init_lexem(0, mul, lex, index_lexema);
            printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
            lex[index_lexema]->two_param = multiply;
            index_lexema++;
        }
        if (ch == '/') {
            printf("DELENIE ");
            init_lexem(0, division, lex, index_lexema);
            printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
            lex[index_lexema]->two_param = _division;
            index_lexema++;
        }
        if (ch == 'x') {
            printf("XXX ");
            init_lexem(0, X, lex, index_lexema);
            printf("i = %d lexem_count = %d enum = %d\n", i, index_lexema, lex[index_lexema]->type);
            index_lexema++;
        }
        i++;
    }
    init_lexem(0, end, lex, index_lexema);
    printf("end\n");
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
    lex[index]->one_param = NULL;
    lex[index]->two_param = NULL;
}

int _isdigit(const char c) {
    int symbol = c - '0';
    if (0 <= symbol && symbol <= 9)
        return 1;
    return 0;
}