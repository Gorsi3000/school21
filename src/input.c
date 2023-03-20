#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "mem.h"
#include "lexema.h"
#include "math_func.h"
#define SIZE 1001

int _isdigit(const char c);
void init_lexem(double value, lexema_type type, lexema **lex, int index);
void clear_array(char arr[], int n);

lexema **input(void) {
    char *string;
    lexema **lex = (lexema **)mem_malloc(sizeof(lexema *) * SIZE);
    string = (char *)mem_malloc(sizeof(char) * SIZE);
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
    while (string[i] != '\0') {
        ch = string[i];
        while (_isdigit(ch)) {
            number[n_index++] = string[i++];
            ch = string[i];
            flag = 1;
        }
        if (flag) {
            double digit = atof(number);
            init_lexem(digit, operand, lex, index_lexema);
            index_lexema++;
            flag = 0;
            clear_array(number, 10);
            n_index = 0;
            i--;
            ch = string[i];
        }

        if (ch == 's') {
            if (string[i + 1] == 'i') {
                init_lexem(0, sinus, lex, index_lexema);
                lex[index_lexema]->one_param = sin;
                i += 1;
                index_lexema++;
            } else {
                init_lexem(0, sqrt_l, lex, index_lexema);
                lex[index_lexema]->one_param = _sqrt;
                i += 3;
                index_lexema++;
            }
        }
        if (ch == 'l') {
            init_lexem(0, log_e, lex, index_lexema);
            lex[index_lexema]->one_param = _log_e;
            i += 1;
            index_lexema++;
        }
        if (ch == 'c') {
            char ch2 = string[i + 1];
            if (ch2 == 'o') {
                init_lexem(0, cosinus, lex, index_lexema);
                lex[index_lexema]->one_param = cos;
                index_lexema++;
                i += 2;
            } else {
                init_lexem(0, cotangens, lex, index_lexema);
                lex[index_lexema]->one_param = ctg;
                i += 1;
                index_lexema++;
            }
        }
        if (ch == 't') {
            init_lexem(0, tangens, lex, index_lexema);
            lex[index_lexema]->one_param = tan;
            i++;
            index_lexema++;
        }
        if (ch == '(') {
            init_lexem(0, bracket_open, lex, index_lexema);
            index_lexema++;
        }
        if (ch == ')') {
            init_lexem(0, bracket_close, lex, index_lexema);
            index_lexema++;
        }
        if (ch == '+') {
            init_lexem(0, plus, lex, index_lexema);
            lex[index_lexema]->two_param = sum;
            index_lexema++;
        }
        if (ch == '-') {
            if (i == 0 || string[i - 1] == '(') {
                init_lexem(0, min_unary, lex, index_lexema);
                lex[index_lexema]->one_param = unary_minus;
                index_lexema++;
            } else {
                init_lexem(0, min_binary, lex, index_lexema);
                lex[index_lexema]->two_param = binary_minus;
                index_lexema++;
            }
        }
        if (ch == '*') {
            init_lexem(0, mul, lex, index_lexema);
            lex[index_lexema]->two_param = multiply;
            index_lexema++;
        }
        if (ch == '/') {
            init_lexem(0, division, lex, index_lexema);
            lex[index_lexema]->two_param = _division;
            index_lexema++;
        }
        if (ch == 'x') {
            init_lexem(0, X, lex, index_lexema);
            index_lexema++;
        }
        i++;
    }
    init_lexem(0, end, lex, index_lexema);
    mem_free(string);
    
    // printf("index = %d", index_lexema);
    // lexema **res_lex = mem_malloc(sizeof(lexema *) * (index_lexema + 1));
    // i = -1;
    // while(++i <= index_lexema)
    //     res_lex[i] = lex[i];

    // mem_free(lex);

    // return res_lex;
    return lex;
}
 
void init_lexem(double value, lexema_type type, lexema **lex, int index) {
    lex[index] = (lexema *)mem_malloc(sizeof(lexema));
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
    if (0 <= symbol && symbol <= 9) return 1;
    return 0;
}

void clear_array(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = '\0';
    }
}