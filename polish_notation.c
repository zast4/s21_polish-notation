#include "polish_notation.h"

char* to_postfix() {
  char* postfix = malloc(sizeof(char) * DEFSIZE);
  stack_c ;
  int oper_i = 0, post_i = 0;
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
        
    }
  }
  printf("\n postfix: %s\n", postfix);
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

  if (!isdigit(c) && c != '.' && c != '-')
    return c;         // 3. Any single char that is not a letter
  if (c == '-' || isdigit(c))  // collect integer part along with - 
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