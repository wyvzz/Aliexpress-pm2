#ifndef ALI_H
#define ALI_H

void load_products(Product **products, int *count, const char *filename);
void save_products(Product *products, int count, const char *filename);
void add_product(Product **products, int *count);
void edit_product(Product *products, int count);
void delete_product(Product **products, int *count);
void list_products(Product *products, int count);
void search_products(Product *products, int count);

#endif