#include "lexer.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "lexema.h"
#include "stack.h"

double evaluate(lexema** lex, double x) {
    int i = 0;
    node* stack_head = NULL;
    lexema *top_operand = NULL, *second_operand = NULL, *new_l = NULL;
    printf("%.lf\n", x);

    while (lex[i]->type != end) {
        // printf("%d\n", i);
        switch (lex[i]->type) {
            case operand:
                new_l = malloc(sizeof(lexema));
                new_l->one_param = lex[i]->one_param;
                new_l->two_param = lex[i]->two_param;
                new_l->type = lex[i]->type;
                new_l->value = lex[i]->value;
                stack_push(&stack_head, new_l);

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
                top_operand->value = lex[i]->one_param(top_operand->value);
                printf("%.1lf  ", top_operand->value);
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
                top_operand->value = lex[i]->two_param(second_operand->value, top_operand->value);
                top_operand->type = operand;
                top_operand->one_param = NULL;
                top_operand->two_param = NULL;
                stack_push(&stack_head, top_operand);
                free(second_operand);
                break;

            case X:
                new_l = malloc(sizeof(lexema));
                new_l->one_param = NULL;
                new_l->two_param = NULL;
                new_l->type = x;
                new_l->value = operand;
                stack_push(&stack_head, new_l);
                break;

            case end:
                break;
        }
        i++;
    }
    new_l = stack_pop(&stack_head);
    double result = new_l->value;
    free(new_l);
    if (stack_head) printf("error");
    // i = 0;
    // while (lex[i]->type != end) {
    //     free(lex[i]);
    //     i++;
    // }
    // удаляем терминальную лексему
    // free(lex[i]);
    // free(lex);

    return result;
}

lexema** postfix_polish_notashion(lexema** l) {
    int i = 0;

    int queue_length = 0;
    lexema* queue[LEX_MAX_SIZE];
    node* op_head = NULL;

    display_lexemas(l);
    while (l[i]->type != end) {
        switch (l[i]->type) {
            case end:
                break;

            case min_binary:
            case plus:
            case division:
            case mul:
                while (op_head &&
                       (is_prefix(op_head->lex->type) ||
                        (is_operator(op_head->lex->type) && prior_cmp(l[i]->type, op_head->lex->type) < 0))) {
                    queue[queue_length++] = stack_pop(&op_head);
                }
                stack_push(&op_head, l[i]);
                break;

            case min_unary:
            case sqrt_l:
            case log_e:
            case sinus:
            case cosinus:
            case tangens:
            case cotangens:
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

    free(l);
    lexema** output = malloc(queue_length * sizeof(lexema*));

    i = 0;

    while (queue[i]->type != end) {
        output[i] = queue[i];
        i++;
    }
    output[i] = queue[i];
    return output;
}

void display_lexemas(lexema** output) {
    int i = 0;
    while (output[i]->type != end) {
        char str[20];
        switch (output[i]->type) {
            case operand:
                sprintf(str, "%.2lf", output[i]->value);
                break;

            case sinus:
                strcpy(str, "sin");
                break;

            case cosinus:
                strcpy(str, "cos");
                break;

            case tangens:
                strcpy(str, "tg");
                break;

            case cotangens:
                strcpy(str, "ctg");
                break;

            case sqrt_l:
                strcpy(str, "sqrt");
                break;

            case log_e:
                strcpy(str, "ln");
                break;

            case min_binary:
                strcpy(str, "-");
                break;

            case min_unary:
                strcpy(str, "-un");
                break;

            case plus:
                strcpy(str, "+");
                break;

            case division:
                strcpy(str, "/");
                break;

            case mul:
                strcpy(str, "*");
                break;

            case X:
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
    switch (x) {
        case sinus:
        case sqrt_l:
        case cosinus:
        case tangens:
        case cotangens:
        case log_e:
            ret = 5;
            break;

        case min_unary:
            ret = 6;
            break;

        case min_binary:
        case plus:
            ret = 2;
            break;

        case mul:
        case division:
            ret = 3;
            break;

        case bracket_open:
            ret = 4;
            break;

        case bracket_close:
            ret = 4;
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
    return priority(a) == priority(b) ? 0 : priority(a) > priority(b) ? 1 : -1;
}

int is_operator(lexema_type type) {
    int ret;
    switch (type) {
        case min_binary:
        case plus:
        case mul:
        case division:
            ret = 1;
            break;

        case sqrt_l:
        case cosinus:
        case tangens:
        case cotangens:
        case log_e:
        case min_unary:
        case sinus:
        case bracket_open:
        case bracket_close:
        case X:
        case end:
        case operand:
            ret = 0;
            break;
    }
    return ret;
}

int is_prefix(lexema_type type) {
    return type == sinus || type == cosinus || type == tangens || type == cotangens || type == min_unary ||
           type == log_e || type == sqrt_l;
}
