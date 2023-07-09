#include "stack.h"

/* pop_c: pop and return top value from stack_c */
char pop_c(stack_c* st) {
    if (st->sp > 0)
      return st->inner[--(st->sp)];
    else {
      printf("error: stack_c empty\n");
      return 0.0;
    }
}

/* push_c: push f onto value stack_c */
void push_c(stack_c* st, char el) {
    if (st->sp > st->stack_size - 2) {
      st->inner = realloc(st->inner, sizeof(char) * st->stack_size * 1.5);
      st->stack_size *= 1.5;
    }
    st->inner[st->sp++] = el;
}

void init_stack_c(stack_c* st) {
    st->stack_size = 1000;
    st->inner = malloc(sizeof(char) * st->stack_size);
    st->sp = 0;
}

void free_stack_c(stack_c* st) {
    free(st->inner);
}