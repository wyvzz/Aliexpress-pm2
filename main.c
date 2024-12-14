#include <stdio.h>
#include <stdlib.h>
#include "Ali.h"


int main() {
    Product *products = NULL;
    int count = 0;

    load_products(&products, &count, "products.txt");

    while (1) {
      int choice;
    do {
        printf("\nМеню:\n");
        printf("1. Вывести товары на экран\n");
        printf("2. Добавить новый товар\n");
        printf("3. Редактировать товар\n");
        printf("4. Удалить товар\n");
        printf("5. Поиск товара\n");
        printf("6. Сохранить и выйти\n");
        printf("Введите номер: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                list_products(products, count);
                break;
            case 2:
                add_product(&products, &count);
                break;
            case 3:
                edit_product(products, count);
                break;
            case 4:
                delete_product(&products, &count);
                break;
            case 5:
                search_products(products, count);
                break;
            case 6:
                save_products(products, count, "products.txt");
                printf("Данные сохранены.\n");
                break;
            default:
                printf("Неверный ввод.\n");
        }
    }

    return 0;
}