#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXLENGTH 1000

int get_line(char s[], int lim);
char* to_postfix(char* expr);
int getop(char s[]);
