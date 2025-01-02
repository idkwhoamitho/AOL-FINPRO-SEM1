#ifndef MENU_H
#define MENU_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"
#include <windows.h>

void addRecordMenu(){
  struct Item data;
  printf("Input Item's Name: ");
  scanf("%s", data.item_name);
  printf("Input Item's Price: );
  scanf("%d", &data.price);
  printf("Input Item's Quantity: ");
  scanf("%d", &data.quantity);
  addItem(data, char* filePath);
}

void showRecordMenu(){
  int rows, price, quantity;
  printf("Number of rows: : ");
  scanf("%d", rows);
  printf("Total Price: ");
  scanf("%d", price);
  printf("Total Stock Quantity: ");
  scanf("%d", quantity);
  printRecord(rows,price,quantity);
}

void printRecord(rows,price,quantity){
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("%-12s %-18s %-19s %-11s %-13s %s\n", "ITEM_ID", "SUPPLIER_ID",  "ITEM_NAME", "PRICE", "QUANTITY", "SALES");
    printf("----------------------------------------------------------------------------------------------------------\n");
    // int size = 6;
    // data = fopen("Product_Catalogue.csv","r");
    readFile();
    int i = 0; total_quantity = 0;
    for(int i = 0; i < rows;i++)
    {
        /* code */
        if(data[i].price <= price && data[i].quantity + total_quantity <= quantity){
        printf("A%-11d S%-17d %-19s %-11d %-13d %d\n", products[i].ID, products[i].productName, products[i].stock, products[i].price);
        printf("%-5d %-20s %-10d %-10.2d\n", products[i].ID, products[i].productName, products[i].stock, products[i].price);
        total_quantity += data[i].quantity;
        i++;
        }
    }
    // fclose(data);
        
}
void printSortedProducts(){
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Product Name", "Stock", "Price");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < jumlahProd; i++)
    {
        /* code */
    	Sleep(50);
        printf("%-5d %-20s %-10d %-10.2d\n", products[i].ID, products[i].productName, products[i].stock, products[i].price);
    }
}

#endif
