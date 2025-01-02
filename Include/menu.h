#ifndef MENU_H
#define MENU_H

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
