#include "polish_notation.h"

// char* to_postfix(char* expr) {
//   int expr_len = strlen(expr);
//   char* postfix = malloc(sizeof(char) * expr_len);
//   int c, i = 0;
//   while ((expr[i++] = c) == ' ' || c == '\t')
//       ;
//   for (i = 0; i < expr_len; ++i) {
//     if (!isdigit(expr[i]) && expr[i] != '.' && expr[i] != '-')
      
//   }
// }

int getop(char* s) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s1[1] = '\0';

  i = 0;
  if (islower(c)) {
    while (islower(s[++i] = c = getch()));
  }
}