#include <stdio.h>
#include "polish_notation.h"
#include "stack.h"

int main() {
  // char s[MAXLENGTH];
  // get_line(s, MAXLENGTH);
  // printf("%s", s);
  // stack_c st_с;
  // init_stack_c(&st_с);
  // push_c(&st_с, 'a');
  // printf("%c", pop_c(&st_с));
  // free_stack_c(&st_с);

  // char s[100];
  // int res;
  // while ((res = getop(s)) != '\n') {
  //   printf("getop returned value: %d; getop s: %s\n", res, s);
  // }
  to_postfix();
  return 0;
}

// int get_line(char s[], int lim) {
//   int c, i = 0;
//   while ((c = getchar()) != EOF && c != '\n' && --lim > 0) 
//     s[i++] = c;
//   s[i] = '\0';
//   return i;
// }