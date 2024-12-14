#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Ali.h"

void load_products(Product **products, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        *count = 0;
        *products = NULL;
        return;
    }

    fscanf(file, "%i\n", count);
    *products = malloc(sizeof(Product) * (*count));
    for (int i = 0; i < *count; i++) {
        fgets((*products)[i].name, sizeof((*products)[i].name), file);
        (*products)[i].name[strcspn((*products)[i].name, "\n")] = 0;
        fgets((*products)[i].category, sizeof((*products)[i].category), file);
        (*products)[i].category[strcspn((*products)[i].category, "\n")] = 0;
        fscanf(file, "%lf\n", &(*products)[i].price);
        fscanf(file, "%lf\n", &(*products)[i].rating);
    }
    fclose(file);
}


void save_products(Product *products, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "%i\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n%.2f\n%.1f\n", products[i].name, products[i].category, products[i].price, products[i].rating);
    }
    fclose(file);
}


void add_product(Product **products, int *count) {
    *products = realloc(*products, sizeof(Product) * (*count + 1));
    printf("Введите название товара: ");
    fgets((*products)[*count].name, sizeof((*products)[*count].name), stdin);
    (*products)[*count].name[strcspn((*products)[*count].name, "\n")] = 0;

    printf("Введите категорию товара: ");
    fgets((*products)[*count].category, sizeof((*products)[*count].category), stdin);
    (*products)[*count].category[strcspn((*products)[*count].category, "\n")] = 0;

    printf("Введите цену товара: ");
    scanf("%lf", &(*products)[*count].price);
    getchar();

    printf("Введите рейтинг продавца (0-5): ");
    scanf("%lf", &(*products)[*count].rating);
    getchar();

    (*count)++;
    printf("Товар добавлен успешно.\n");
}


void edit_product(Product *products, int count) {
    char name[100];
    printf("Введите название товара для редактирования: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Введите новую категорию товара: ");
            fgets(products[i].category, sizeof(products[i].category), stdin);
            products[i].category[strcspn(products[i].category, "\n")] = 0;

            printf("Введите новую цену товара: ");
            scanf("%lf", &products[i].price);
            getchar();

            printf("Введите новый рейтинг продавца (0-5): ");
            scanf("%lf", &products[i].rating);
            getchar();

            printf("Товар обновлён успешно.\n");
            return;
        }
    }
    printf("Товар не найден.\n");
}


void delete_product(Product **products, int *count) {
    char name[100];
    printf("Введите название товара для удаления: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < *count; i++) {
        if (strcmp((*products)[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                (*products)[j] = (*products)[j + 1];
            }
            *products = realloc(*products, sizeof(Product) * (--(*count)));
            printf("Товар удалён успешно.\n");
            return;
        }
    }
    printf("Товар не найден.\n");
}


void list_products(Product *products, int count) {
    printf("Список товаров:\n");
    for (int i = 0; i < count; i++) {
        printf("\nНазвание: %s\nКатегория: %s\nЦена: %.2f$\nРейтинг: %.1f\n",
               products[i].name, products[i].category, products[i].price, products[i].rating);
    }
}


void search_products(Product *products, int count) {
    char name[100];
    printf("Введите название товара для поиска: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Результаты поиска:\n");
    for (int i = 0; i < count; i++) {
        if (strstr(products[i].name, name)) {
            printf("\nНазвание: %s\nКатегория: %s\nЦена: %.2f$\nРейтинг: %.1f\n",
                   products[i].name, products[i].category, products[i].price, products[i].rating);
        }
    }
}