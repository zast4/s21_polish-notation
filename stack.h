#include <stdlib.h>
#include <stdio.h>

typedef struct stack_c {
  int sp;
  int stack_size;
  char* inner;
} stack_c;

typedef struct stack_d {
  int sp;
  char* inner;
} stack_d;

char pop_c(stack_c* st);
void push_c(stack_c* st, char el);
void init_stack_c(stack_c* st);
void free_stack_c(stack_c* st);

char pop_d(stack_d* st);
void push_d(stack_d* st, char el);
void init_stack_d(stack_d* st);
void free_stack_d(stack_d* st);

