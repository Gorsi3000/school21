#include "stack.h"
// #include "tree.h"
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
void display_lexemas(lexema** output, int output_length);
int is_operator(lexema_type type);

int t(void);

int main(){
   t();
    return 0;
}

int t(void) {
    // lexema l_tmp[6] = {{ 2, operand, NULL, NULL},
    //                { 0, plus, NULL, NULL},
    //                { 3, operand, NULL, NULL},
    //                { 0, mul, NULL, NULL},
    //                { 4, operand, NULL, NULL},
    //                { 0, end, NULL, NULL}};
    int i = 0;
    lexema** l = input();
    // lexema** l = malloc(sizeof(lexema*) * 6);
    // while (i < 6) l[i] = &l_tmp[i];
    // i = 0;
    int output_length = 0;
    lexema* output[LEX_MAX_SIZE];
    node* op_head = NULL;

    int len = 0;
    while (l[len]->type != end) ++len;
    display_lexemas(l, len);


    while (l[i]->type != end) {
        switch (l[i]->type)
        {
            case end:
                break;

            case min_binary:
            case plus:
            case division:
            case mul:
                while (op_head && (is_prefix(op_head->lex->type) || 
                        (is_operator(op_head->lex->type) && 
                         prior_cmp(l[i]->type, op_head->lex->type) < 0))) {
                    output[output_length++] = stack_pop(&op_head);
                }
                stack_push(&op_head, l[i]);
                break;

            case sqrt_l:
            case log_e:
            case sinus:
            case cosinus:
            case tangens:
            case cotangens:
            case min_unary:
            case bracket_open:
                stack_push(&op_head, l[i]);
                break;

            case bracket_close:
                while (op_head && op_head->lex->type != bracket_open) {
                    output[output_length++] = stack_pop(&op_head);
                }
                // могут быть проблемы, если не найдена открывающая скобка
                // или если неверно поставлени разделитель
                // необходимо обработать эти ситуацию
                if (op_head) free(stack_pop(&op_head)); 
                break;

            case operand:
            case X:
                output[output_length++] = l[i];
                // if (!val_head) val_head = stack_node_create(&l[i]);
                // else stack_push(&val_head, &l[i]);
                break;
        }
        i++;
    }
    while (op_head) output[output_length++] = stack_pop(&op_head);
    display_lexemas(output, output_length);

    i = 0;
    //while(l[i]->type != end) free(l[i]);
    free(l);

    return 0;
}

void display_lexemas(lexema** output, int output_length) {
    int i = 0;
    while(i < output_length) {
        char str[20];
        switch (output[i]->type)
        {
            case operand :   
                sprintf(str, "%.2lf", output[i]->value);
            break;

            case sinus :
                strcpy(str, "sin");
            break;

            case cosinus :
                strcpy(str, "cos");
            break;

            case tangens :
                strcpy(str, "tg");
            break;

            case cotangens :
                strcpy(str, "ctg");
            break;

            case sqrt_l :
                strcpy(str, "sqrt");
            break;

            case log_e :
                strcpy(str, "ln");
            break;

            case min_binary :
                            strcpy(str, "-");
            break;

            case min_unary :
                strcpy(str, "-un");
            break;

            case plus :
                strcpy(str, "+");
            break;

            case division :
                strcpy(str, "/");
            break;

            case mul :
                strcpy(str, "*");
            break;

            case X :
                strcpy(str, "x");
            break;

            case bracket_open:
                strcpy(str, "(");
            break;
            
            case bracket_close:
                strcpy(str, ")");
            break;

            default:
                sprintf(str, "err type: %d, i:%d", output[i]->type, i);
        }
        i++;
        printf("%s ", str);     
    } 
    printf("\n");
}

int priority(lexema_type x) {
    int ret;
    switch (x)
    {
        case min_binary:
        case plus:
            ret = 1;
        break;


        case mul:
        case division:
            ret = 2;
        break;

        case sqrt_l:
            ret = 3;
        break;

        case bracket_open:
            ret = 4;
        break;

        case bracket_close:
            ret = 4;
        break;

        case cosinus:
        case tangens:
        case cotangens:
        case log_e:
        case min_unary:
        case sinus:
            ret = 1;
            ret = 1;
        break;

        case X:
        case end:
        case operand:
            ret = -1;
        break;
    }
    return ret;
}

int prior_cmp(lexema_type a, lexema_type b) {
    return priority(a) == priority(b) ? 0 : 
           priority(a) > priority(b) ? 1 : -1;
}

int is_operator(lexema_type type) {
    int ret;
    switch (type)
    {
        case min_binary:
        case plus:
        case mul:
        case division:
            ret = 1;
        break;

        case sqrt_l:
        case bracket_open:
        case bracket_close:
        case cosinus:
        case tangens:
        case cotangens:
        case log_e:
        case min_unary:
        case sinus:
        case X:
        case end:
        case operand:
            ret = 0;
        break;
    }
    return ret;
}

int is_prefix(lexema_type type) {
    return type == sinus ||     \
            type == cosinus ||  \
            type == tangens ||  \
            type == cotangens ||\
            type == min_unary;
}
