#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


#define DEFSIZE 1000
#define MAXOP 100
#define NUMBER '0' /* signal that a number was found */
#define NAME 'n'

// int get_line(char s[], int lim);
char* to_postfix();
int getop(char s[]);
