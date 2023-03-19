
#include "lexema.h"
#include "input.h"
#include "stack.h"
#include "lexer.h"
#include "math.h"
// #include "output"
#define HEIGHT 25
#define WIDTH 80 

int main(void){

    lexema** lex = postfix_polish_notashion(input());
    double arr[WIDTH];
    double y;
    int i = 0;
    for (double x = 0; x < 4 * M_PI; x += 4 * M_PI / (WIDTH)) {
        // break;
        y = evaluate(lex, x);
        arr[i++] = y;
    }
    i = (int) arr[0];

    i = 0;
    while (lex[i]->type != end) {
        free(lex[i]);
        i++;
    }
    // удаляем терминальную лексему
    free(lex[i]);
    free(lex);
    return 0;
}
