#include "stack.h"
#include "tree.h"
#include <math.h>
 
int main(void){
    lexema l[5] = {{ 2, operand}, \
                   { 1, operand}, \
                   { 0, plus}, \
                   { 2, operand}, \
                   { 0, mul}};

    int i = 0;
    node* head;
    lexema l_tmp;
    while (i < 5)
    {
        if (i == 0)
            head = stack_init(&l[0]);
        else {
            switch (l[i].type)
            {
                case sinus:
                case cosinus:
                case tg:
                case ctg:
                case min_unary:
                case min_binary:
                    break;

                case plus:
                case division:
                case mul:
                    l_tmp = stack_pop(head);
            
                    break;

                case bracket_open:
                case bracket_close:
                case operand:
                case X:
                    stack_push(&head, l[i]);
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