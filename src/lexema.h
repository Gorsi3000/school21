#ifndef LEXEMA_H
#define LEXEMA_H

enum lexem_type{
  operand,
  sin,
  cos,
  tg,
  ctg,
  min_unary,
  min_binary,
  plus,
  div,
  mul,
  bracket_open,
  bracket_close,
  X 
};

typedef struct lexema
{
    double value;
    enum lexem_type type;
} lexema;

#endif