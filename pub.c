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