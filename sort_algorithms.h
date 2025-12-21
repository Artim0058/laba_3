#pragma once
#include "pub.h"
typedef int (*Comparator)(const Publication*, const Publication*);
void insertion_sort(void* container,
                   void* (*get_at)(void*, int),
                   void (*swap)(void*, int, int),
                   int size,
                   Comparator cmp);