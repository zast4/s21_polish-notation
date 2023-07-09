#include "polish_notation.h"
#include "stack.h"

char* to_postfix() {
  char* postfix = malloc(sizeof(char) * DEFSIZE);
  stack_c stack;
  init_stack_c(&stack);
  int oper_i = 0, post_i = 0;
  char oper_in_st = 0;
  char cur_oper = 0;
  int type;
  char oper[MAXOP];

  while ((type = getop(oper)) != EOF) {
    switch(type) {
      case NUMBER:
        while (oper[oper_i] != '\0')
          postfix[post_i++] = oper[oper_i++];
        postfix[post_i++] = ' ';
        oper_i = 0;
        break;
      case NAME:
        if (is_operator(oper) != -1) {
          if (strcmp(oper, "ctg") == 0)
            cur_oper = 'g';
          else if (strcmp(oper, "sqrt") == 0)
            cur_oper = 'q';
          else 
            cur_oper = oper[0];
        }
      case '+':
      case '-':
      case '*':
      case '/':
        if (stack.sp != 0) {
          while (operator_priority(oper_in_st) != -1 && operator_priority(oper_in_st) >= operator_priority(cur_oper) && stack.sp != 0) {
            oper_in_st = pop_c(&stack);
            if (type != NAME)
              cur_oper = type;
            if (operator_priority(oper_in_st) >= operator_priority(cur_oper)) {  // If operator priority in stack is higher than current operator, we extract this operator from stack to postfix srting
              postfix[post_i++] = oper_in_st;
              postfix[post_i++] = ' ';
            }
            else {
              push_c(&stack, oper_in_st);
            }
          }
        }
        
        push_c(&stack, cur_oper);
        break;
    }
  }
  while (stack.sp > 0) {
    postfix[post_i++] = pop_c(&stack);
    postfix[post_i++] = ' ';
  }
  printf("\n postfix: %s\n", postfix);
  printf("\n stack_c: %s\n", stack.inner);
  return postfix;
}


int getop(char* s) {
  int i, c;

  while ((s[0] = c = getchar()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  i = 0;
  if (islower(c)) {
    while (islower(s[++i] = c = getchar()));
    s[i] = '\0';
    if (c != EOF)
      ungetc(c, stdin); 
    if (strlen(s) > 1)
      return NAME;    // 1. Any chars' sequence in lower case
    else
      return s[0];    // 2. Any single char in lower case
  }

  if (!isdigit(c) && c != '.' && c != '~')
    return c;         // 3. Any single char that is not a letter
  if (c == '~' || isdigit(c))  // collect integer part along with - 
    while (isdigit(s[++i] = c = getchar()))
      ;
  if (c == '.')  // collect fraction part
    while (isdigit(s[++i] = c = getchar()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetc(c, stdin);
  if (strcmp(s, "-") == 0)
    return '-';       // 4. Minus with two operands
  return NUMBER;      // 5. Any number
}


int operator_priority(char c) {
  int res = -1;
  if (c == '(')
    res = 0;
  else if (c == '~')
    res = 3;
  else if (c == '+' || c == '-')
    res = 1;
  else if (c == '*' || c == '/')
    res = 2;
  else if (c == 's' || c == 'c' || c == 't' || c == 'g' || c == 'q' || c == 'l')
    res = 3;
  return res;
}

int is_operator(char s[]) {
  int res = -1;
  if (strcmp(s, "(") == 0)
    res = 0;
  else if (strcmp(s, "~") == 0)
    res = 3;
  else if (strcmp(s, "+") == 0 || strcmp(s, "-") == 0)
    res = 1;
  else if (strcmp(s, "*") == 0 || strcmp(s, "/") == 0)
    res = 2;
  else if (strcmp(s, "sin") == 0 || strcmp(s, "cos") == 0 || strcmp(s, "tan") == 0 || strcmp(s, "ctg") == 0 || strcmp(s, "sqrt") == 0 || strcmp(s, "ln") == 0)
    res = 3;
  return res;
}