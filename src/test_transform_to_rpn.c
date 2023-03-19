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

int main(){

   lexema** l = postfix_polish_notashion(input());

    for (double x = 0;)
   evaluate(l, x);
   return 0;
}

double evaluate (lexema** lex, double x) {
    int i = 0;
    lexema* l[LEX_MAX_SIZE];
    node* stack_head = NULL;
    lexema* top_operand = NULL, *second_operand = NULL;

    while(lex[i]->type != end)
    {
        switch (lex[i]->type)
        {
            case operand:
                stack_push(&stack_head, l[i]);

            case bracket_open:
            case bracket_close:
                break;

            case sinus:
            case cosinus:
            case tangens:
            case cotangens:
            case sqrt_l:
            case log_e:
            case min_unary:
                top_operand = stack_pop(&stack_head);
                top_operand->value = l[i]->one_param(top_operand->value);
                top_operand->type = operand;
                top_operand->one_param = NULL;
                top_operand->two_param = NULL;
                stack_push(&stack_head, top_operand);
            break;

            case min_binary:
            case plus:
            case division:
            case mul:
                top_operand = stack_pop(&stack_head);
                second_operand = stack_pop(&stack_head);
                top_operand->value = l[i]->two_param(top_operand->value, second_operand->value);
                top_operand->type = operand;
                top_operand->one_param = NULL;
                top_operand->two_param = NULL;
                stack_push(&stack_head, top_operand);
                break;

            case X:
                l[i]->value = x;
                l[i]->type = operand;
                stack_push(&stack_head, l[i]);
                break;

            case end: 
                break;
        }
        
    }
    double result = stack_pop(&stack_head)->value;
    i = 0;
    while (l[i]->type != end) {
        free(l[i]);
        i++;
    }
    // удаляем терминальную лексему
    free(l[i]);
    free(l);

    return result;
}


lexema** postfix_polish_notashion(lexema** l ) {
    // lexema l_tmp[6] = {{ 2, operand, NULL, NULL},
    //                { 0, plus, NULL, NULL},
    //                { 3, operand, NULL, NULL},
    //                { 0, mul, NULL, NULL},
    //                { 4, operand, NULL, NULL},
    //                { 0, end, NULL, NULL}};
    int i = 0;
    // lexema** l = malloc(sizeof(lexema*) * 6);
    // while (i < 6) l[i] = &l_tmp[i];
    // i = 0;
    int queue_length = 0;
    lexema* queue[LEX_MAX_SIZE];
    node* op_head = NULL;

    // int len = 0;
    // while (l[len]->type != end) ++len;
    display_lexemas(l);


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
                    queue[queue_length++] = stack_pop(&op_head);
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
                    queue[queue_length++] = stack_pop(&op_head);
                }
                // могут быть проблемы, если не найдена открывающая скобка
                // или если неверно поставлени разделитель
                // необходимо обработать эти ситуацию
                if (op_head) free(stack_pop(&op_head)); 
                break;

            case operand:
            case X:
                queue[queue_length++] = l[i];
                // if (!val_head) val_head = stack_node_create(&l[i]);
                // else stack_push(&val_head, &l[i]);
                break;
        }
        i++;
    }
    while (op_head) queue[queue_length++] = stack_pop(&op_head);
    queue[queue_length++] = l[i];
    display_lexemas(queue);

    // i = 0;
    // while(l[i]->type != end) free(l[i]);
    free(l);

    lexema** output = malloc(queue_length * sizeof(lexema*));

    i = 0;
    while (queue[i]->value != end){
        output[i] = queue[i];
        i++;
    }
    return output;
}

void display_lexemas(lexema** output) {
    int i = 0;
    while(output[i]->type != end) {
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
