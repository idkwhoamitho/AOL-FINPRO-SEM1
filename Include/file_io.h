#ifndef FILEIO_H
#define FILEIO_H

#include "data_processing.h"
#include <stdio.h>

int getLength(const char* filePath);

void createFile(const char* filePath);
void rewriteInventory(struct Inventory *data,const char* filePath);
void rewriteSupplier(struct Supplier *data,const char* filePath);
void rewriteItem(struct Item *data,const char* filePath);



struct Inventory* readFileInventory(const char* filePath);
struct Supplier* readFileSupplier(const char* filePath);
struct Item* readFileItem(const char* filePath);






#endif