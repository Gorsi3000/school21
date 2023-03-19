#ifndef LEXEMA_H
#define LEXEMA_H

typedef enum {
    operand,
    sinus,
    cosinus,
    tangens,
    cotangens,
    sqrt_l,
    log_e,
    min_unary,
    min_binary,
    plus,
    division,
    mul,
    bracket_open,
    bracket_close,
    X,
    end
} lexema_type;

typedef struct lexema
{
    double value;
    lexema_type type;
    double (*one_param)(double a);
    double (*two_param)(double a, double b);
} lexema;

#endif
