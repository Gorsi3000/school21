#ifndef LEXEMA_H
#define LEXEMA_H

enum {
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
} lexem_type;

typedef struct lexema
{
    double value;
    lexem_type type;

} lexema;

#endif