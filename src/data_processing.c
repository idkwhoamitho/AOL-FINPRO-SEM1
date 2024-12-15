#include "data_processing.h"

int getInventoryById(struct Inventory* Inventory, int id){
    int i = 0;
    int found;
    int index = -1;
    int size = sizeof(Inventory) / sizeof(Inventory[0]);
    for (;i < size; i++)
    {
        /* code */
        found++;
        if(Inventory[i].item_id == id) {
            index = i;
            break;
        }        
    }

    return index;    
}


int getItemById(struct Item* Item, int id){
     int i = 0;
    int found;
    int index = -1;
    int size = sizeof(Item) / sizeof(Item[0]);
    for (;i < size; i++)
    {
        /* code */
        found++;
        if(Item[i].id == id) {
            index = i;
            break;
        }        
    }

    return index;    
}

int getSuplierById(struct Supplier* Suplier, int id){
     int i = 0;
    int found;
    int index = -1;
    int size = sizeof(Suplier) / sizeof(Suplier[0]);
    for (;i < size; i++)
    {
        /* code */
        found++;
        if(Suplier[i].id == id) {
            index = i;
            break;
        }        
    }

    return index;  
}




void sortById(struct Inventory* Inventory){
    struct Inventory temp;
    int jumlahInventory = sizeof(Inventory)/sizeof(Inventory[0]);
    int sortType = 0;
       while (1)
       {
            printf("Ascending or Descending ?\n");
            printf("Ascending = 1\n");
            printf("Descending = 2\n");
            printf("Your Choice : ");
            scanf("%d", &sortType);
            if(sortType == 1) break;
            else if(sortType == 2) break;
       }
    if(sortType == 1){
        for (int i = 0; i < jumlahInventory - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahInventory - i -1; j++)
            {
                /* code */
                if(Inventory[j].item_id > Inventory[j+1].item_id){
                    temp = Inventory[j];
                    Inventory[j] = Inventory[j + 1];
                    Inventory[j + 1] = temp;
                }
            }
            
        }
        
    }
}

void sortByQuantity(struct Inventory* inventory){
    struct Inventory temp;
    int jumlahInventory = sizeof(inventory)/sizeof(inventory[0]);
    int sortType = 0;
       while (1)
       {
            printf("Ascending or Descending ?\n");
            printf("Ascending = 1\n");
            printf("Descending = 2\n");
            printf("Your Choice : ");
            scanf("%d", &sortType);
            if(sortType == 1) break;
            else if(sortType == 2) break;
       }
    if(sortType == 1){
        for (int i = 0; i < jumlahInventory - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahInventory - i -1; j++)
            {
                /* code */
                if(inventory[j].quantity > inventory[j+1].quantity){
                    temp = inventory[j];
                    inventory[j] = inventory[j + 1];
                    inventory[j + 1] = temp;
                }
            }
            
        }
        
    }
}



// add
void addInventory(struct Inventory data, const char* filePath){
    FILE *file = fopen(filePath,"a");
    fprintf(file,"\n%d,%d,%d",
        data.item_id,
        data.supplier_id,
        data.quantity
    );
    fclose(file);
}
void addSupplier(struct Supplier data, const char* filePath){
    FILE *file = fopen(filePath,"a");
    fprintf(file,"\n%d,%s,%s",
        data.id,
        data.name,
        data.phone_number
    );
    fclose(file);

}
void addItem(struct Item data, const char* filePath){
    FILE *file = fopen(filePath,"a");
    fprintf(file,"\n%d,%s,%f",
        data.id,
        data.item_name,
        data.price
    );
    fclose(file);
}


//update
void updateInventory(struct Inventory *data,int id,struct Inventory updatedData ,const char* filePath){
    int size = get_lenght(filePath);
    int index = getInventoryById(data,id);
    if(index == -1){
        perror("Record not found!");
        return;
    }
    for(int i = 0;i < size;i++){
        if(index == i){
            data[i].item_id = updatedData.item_id;
            data[i].supplier_id = updatedData.supplier_id;
            data[i].quantity = updatedData.quantity;
        }

    }
    rewriteInventory(data,filePath);

}
void updateSupplier(struct Supplier *data,struct Supplier updatedData,int id ,const char* filePath){
    int size = get_lenght(filePath);
    int index = getInventoryById(data,id);
    if(index == -1){
        perror("Record not found!");
        return;
    }
    for(int i = 0;i < size;i++){
        if(index == i){
            data[i].id = updatedData.id;
            strcpy(data[i].name,updatedData.name);
            strcpy(data[i].phone_number,updatedData.phone_number);
        }

    }
    rewriteInventory(data,filePath);
}
void updateItem(struct Item *data,struct Item updatedData,int id ,const char* filePath){
     int size = get_lenght(filePath);
    int index = getInventoryById(data,id);
    if(index == -1){
        perror("Record not found!");
        return;
    }
    for(int i = 0;i < size;i++){
        if(index == i){
            data[i].id = updatedData.id;
            strcpy(data[i].item_name,updatedData.item_name);
            data[i].price = updatedData.price;            
        }

    }
    rewriteInventory(data,filePath);
}

//delete
void deleteInventory(struct Inventory *data,int id, const char* filePath){
    int size = get_lenght(filePath);
    int index = getInventoryById(data,id);
    struct Inventory temp[size - 1];
    if(index == -1){
        perror("Record not found!");
        return;
    }
    int size = get_lenght(filePath);
    int index = getInventoryById(data,id);
    if(index == -1){
        perror("Record not found!");
        return;
    }
    for(int i = 0;i < size;i++){
        if(i != index){
            temp[i] = data[i];
        }
    }

    rewriteInventory(temp,filePath);
}
void deleteSupplier(struct Supplier *data,int id, const char* filePath){
    int size = get_lenght(filePath);
    int index = getInventoryById(data,id);
    struct Supplier temp[size - 1];
    if(index == -1){
        perror("Record not found!");
        return;
    }
    int size = get_lenght(filePath);
    int index = getInventoryById(data,id);
    if(index == -1){
        perror("Record not found!");
        return;
    }
    for(int i = 0;i < size;i++){
        if(i != index){
            temp[i] = data[i];
        }
    }

    rewriteSupplier(temp,filePath);
}
void deleteItem(struct Item *data,int id, const char* filePath){
    int size = get_lenght(filePath);
    int index = getInventoryById(data,id);
    struct Item temp[size - 1];
    if(index == -1){
        perror("Record not found!");
        return;
    }
    int size = get_lenght(filePath);
    int index = getInventoryById(data,id);
    if(index == -1){
        perror("Record not found!");
        return;
    }
    for(int i = 0;i < size;i++){
        if(i != index){
            temp[i] = data[i];
        }
    }

    rewriteItem(temp,filePath);
}