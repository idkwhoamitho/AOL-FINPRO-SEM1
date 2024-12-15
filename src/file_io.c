#include "file_io.h"


int get_length(const char* filePath){
    int count = 0;
    FILE *file = fopen(filePath,"r");
    if(file == NULL){
        perror("Can't open file");
        return -1;
    }
    while (!feof(file))
    {
        /* code */
        count++;
    }
    return count;
    
}
void createFile(const char* filePath){
    FILE *data = fopen(filePath,"w");
    if (data == NULL)
    {
        /* code */
        perror("An error has occured");
    }
    fclose(data);     
}

struct Inventory* readFileInventory(const char* filePath){
    FILE *data = fopen(filePath,"r");
    int index = get_length(filePath);
    
    struct Inventory inventory[index];
    int i = 0;
    if (data == NULL)
    {
        /* code */
        perror("An error has occured");
    }
    char line[1024];
    int index = 0;

    // Skip the header line
    fgets(line, sizeof(line), data);

    while (fscanf(data,"%d,%d,%d",&inventory[i].item_id,&inventory[i].supplier_id,&inventory[i].quantity) == 4)
    {
        i++;
    }
    fclose(data);     
    return inventory; 
}

struct Supplier* readFileSupplier(const char* filePath){
    FILE *data = fopen(filePath,"r");
    int index = get_length(filePath);
    
    struct Supplier supplier[index];
    int i = 0;
    if (data == NULL)
    {
        /* code */
        perror("An error has occured");
    }
    char line[1024];
    int index = 0;

    // Skip the header line
    fgets(line, sizeof(line), data);

    while (fscanf(data,"%d,%s,%s",&supplier[i].id,supplier[i].name,&supplier[i].phone_number) == 4)
    {
        i++;
    }
    fclose(data);     
    return supplier; 
}


struct Item* readFileItem(const char* filePath){
    FILE *data = fopen(filePath,"r");
    int index = get_length(filePath);
    
    struct Item Item[index];
    int i = 0;
    if (data == NULL)
    {
        /* code */
        perror("An error has occured");
    }
    char line[1024];
    int index = 0;

    // Skip the header line
    fgets(line, sizeof(line), data);

    while (fscanf(data,"%d,%s,%f",&Item[i].id,Item[i].item_name,&Item[i].price) == 4)
    {
        i++;
    }
    fclose(data);     
    return Item; 
}

void rewriteInventory(struct Inventory *data,const char* filePath){
   FILE *file = fopen(filePath,"r");
   int size = get_length(filePath);

   for (int i = 0; i < filePath; i++)
   {
    /* code */
        fprintf(file,"\n%d,%d,%d",
        data[i].item_id,
        data[i].supplier_id,
        data[i].quantity
        );
   }
   fclose(file);
   printf("Data updated");       
}


void rewriteSupplier(struct Supplier *data,const char* filePath){
    FILE *file = fopen(filePath,"r");
   int size = get_length(filePath);

   for (int i = 0; i < filePath; i++)
   {
    /* code */
        fprintf(file,"\n%d,%s,%s",
        data[i].id,
        data[i].name,
        data[i].phone_number
        );
   }
   fclose(file);
   printf("Data updated");       
}

void rewriteItem(struct Item *data,const char* filePath){
    FILE *file = fopen(filePath,"r");
   int size = get_length(filePath);

   for (int i = 0; i < filePath; i++)
   {
    /* code */
        fprintf(file,"\n%d,%s,%f",
        data[i].id,
        data[i].item_name,
        data[i].price
        );
   }
   fclose(file);
   printf("Data updated");       
}



