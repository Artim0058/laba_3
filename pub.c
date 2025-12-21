#include "pub.h"
#include <stdio.h>
#include <string.h>
void pub_print(const Publication* p) {
    if (!p) return;
    printf("\"%s\",\"%s\",\"%s\",\"%s\",%d,%d,%s,%d,%d\n",
           p->title, p->author_surname, p->author_initials,
           p->journal, p->year, p->volume,
           p->is_rinc ? "YES" : "NO",
           p->pages, p->citations);
}
int pub_compare(const Publication* a, const Publication* b, bool ascending) {
    if (!a || !b) return 0;
    int result = a->year - b->year;
    if (result == 0) result = a->citations - b->citations;
    if (result == 0) result = strcmp(a->title, b->title);
    return ascending ? result : -result;
}