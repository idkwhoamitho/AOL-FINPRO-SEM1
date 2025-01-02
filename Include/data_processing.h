#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H
#include <stdio.h>

#include "file_io.h"
struct Item {
    int id;
    char item_name[50];
    float price;
    int quantity;
};

struct Supplier {
    int id;
    char name[50];
    char phone_number[20];
};

struct Inventory {
    int item_id;
    int supplier_id;
    int quantity;
};

int getInventoryById(struct Inventory* Inventory, int id);
int getItemById(struct Item* Item, int id);
int getSuplierById(struct Supplier* Suplier, int id);

void sortById(struct Inventory* inventory);
void sortByQuantity(struct Inventory* inventory);

// add
void addInventory(struct Inventory data, const char* filePath);
void addSupplier(struct Supplier data, const char* filePath);
void addItem(struct Item data, const char* filePath);

//update
void updateInventory(struct Inventory *data,int id,struct Inventory updatedData ,const char* filePath);
void updateSupplier(struct Supplier *data,struct Supplier updatedData,int id ,const char* filePath);
void updateItem(struct Item *data,struct Item updatedData,int id ,const char* filePath);

//delete
void deleteInventory(struct Inventory *data,int id, const char* filePath);
void deleteSupplier(struct Supplier *data,int id, const char* filePath);
void deleteItem(struct Item *data,int id, const char* filePath);




#endif
