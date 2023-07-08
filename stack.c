#include "stack.h"

/* pop_c: pop and return top value from stack_c */
char pop_c(stack_c* st) {
    if (st->sp > 0)
      return st->inner[--(st->sp)];
    else {
      printf("error: stack_c_c empty\n");
      return 0.0;
    }
}

/* push_c: push f onto value stack_c */
void push_c(stack_c* st, char el) {
    st->inner[st->sp++] = el;
}

void init_stack_c(stack_c* st) {
    st->inner = malloc(sizeof(char) * 1000);
    st->sp = 0;
}

void free_stack_c(stack_c* st) {
    free(st->inner);
}