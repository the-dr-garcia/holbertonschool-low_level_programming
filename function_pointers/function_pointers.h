#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef unsigned long size_t;

int int_index(int *array, int size, int (*cmp)(int));
void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
int _putchar(char c);

#endif
