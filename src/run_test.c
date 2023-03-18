#include "stack.h"
#include "tree.h"
#include <math.h>
int is_prefix(enum lexema_type type) {
    return type == sinus ||     \
            type == cosinus ||  \
            type == tangens ||  \
            type == cotangens ||\
            type == min_unary;
} 

int main(void){
    lexema l[5] = {{ 2, operand}, \
                   { 0, plus}, \
                   { 3, operand}, \
                   { 0, mul}, \
                   { 4, operand}};

    int i = 0;
    lexema* output[100];
    int output_length = 0;
    // node* val_head;
    node* op_head;
    lexema *l_tmp1, *l_tmp2;
    while (i < 5) {
        switch (l[i].type)
        {
            case min_binary:
            case plus:
            case division:
            case mul:
                while (is_prefix(op_head->lex->type) ||) {

                }
                break;
            case sinus:
            case cosinus:
            case tangens:
            case cotangens:
            case min_unary:
                if (!op_head) op_head = stack_init(&l[i]);
                else stack_push(op_head, &l[i]);
                break;

            case bracket_close:
                while (op_head->lex->type != bracket_open) {
                    output[output_length++] = stack_pop(&op_head);
                }
                // могут быть проблемы, если не найдена открывающая скобка
                // или если неверно поставлени разделитель
                // необходимо обработать эти ситуацию
                free(stack_pop(&op_head));

                break;

            case bracket_open:
            case operand:
            case X:
                output[output_length++] = &l[i];
                // if (!val_head) val_head = stack_init(&l[i]);
                // else stack_push(&val_head, &l[i]);
                break;
        }
            /* 
            switch (l[i].type)
            {
                case operand:
                case X:
                    stack_push(&head, &l[i]);
                    break;

                case sin:
                    break;

                case cos:
                    break;

                case tg:
                    break;

                case ctg:
                    break;

                case min_unary:
                    break;

                case min_binary:
                    break;

                case plus:
                    break;

                case division:
                    break;

                case mul:
                    break;

                case bracket_open:
                    break;

                case bracket_close:
                    break;
            }
            */
        }
    }

    if (head) stack_destroy(&head);
    return 0;
}