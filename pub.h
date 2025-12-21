#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

// Структура для хранения записи о научной публикации
typedef struct {
    char title[256];           // Название публикации
    char author_surname[100];  // Фамилия первого автора
    char author_initials[10];  // Инициалы первого автора
    char journal[150];         // Название журнала
    int year;                  // Год публикации
    int volume;                // Том журнала
    bool is_rinc;              // Входит в РИНЦ
    int pages;                 // Количество страниц
    int citations;             // Цитирований
} Publication;

// Функции для работы с Publication
void pub_print(const Publication* p);
void pub_print_table(const Publication* p);
int pub_compare(const Publication* a, const Publication* b, bool ascending);
int pub_compare(const Publication* a, const Publication* b, bool ascending);
