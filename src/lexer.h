#include "stack.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lexema.h"
#include "input.h"

// Максимальная длина массива лексем
#define LEX_MAX_SIZE 100

int priority(lexema_type x);        
int is_prefix(lexema_type type);
int prior_cmp(lexema_type a, lexema_type b);
void display_lexemas(lexema** output);
int is_operator(lexema_type type);
double evaluate (lexema** lex, double x);
lexema** postfix_polish_notashion(lexema** l );