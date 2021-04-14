#ifndef ALGORYTHMS_H
#define ALGORYTHMS_H

#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>
#include <memory.h>

void sort_swap(void *buf0, void *buf1, size_t size);
void *bubble_sort(void *buf, size_t length, size_t step, bool( *pfnCheck)(void *el0, void *el1));
void *insertion_sort(void *buf, size_t length, size_t step, bool( *pfnCheck)(void *el0, void *el1));

#endif