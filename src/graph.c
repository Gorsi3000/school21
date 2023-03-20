#define _USE_MATH_DEFINES
//#define __MSDOS__ 1
#define VAX11C 1
#define M_UNIX 1

#include "input.h"
#include "lexema.h"
#include "lexer.h"
#include "math.h"
#include "output.h"
#include "mem.h"
// #include "toolkit.h"
#include "stack.h"


#define HEIGHT 25
#define WIDTH 80

int main(void) {
    mem_init();
    // atexit(mem_term);

    lexema** lex = input();    
     lex = postfix_polish_notashion(lex);

    // mem_check() ;
    double arr[WIDTH];
    double y;
    int i = 0;
    for (double x = 0; x < 4 * M_PI; x += 4 * M_PI / (WIDTH - 1)) {
        // break;
        y = evaluate(lex, x);
        arr[i++] = y;
    }
    output_v2(arr);

    i = -1;
    while (lex[++i]->type != end)
        mem_free(lex[i]);
    // удаляем терминальную лексему
    mem_free(lex[i]);
    mem_free(lex);

    mem_term();

    return 0;
}
