#include <stdio.h>
#include "data_processing.h"
#include "menu.h"
#include "fileIO.h"

int getInventoryById(struct Inventory* Inventory, int id){
    int i = 0;
    int found;
    int index;
    int size = sizeof(Inventory) / sizeof(Inventory[0]);
    for (;i < size; i++)
    {
        /* code */
        found++;
        if(Inventory[i].ID == id) {
            *index = i;
            break;
        }        
    }
    
    return index;
    
}

void menu() {
    int choose;
    
     while(1){
        printf("INVENTORY SYSTEM\n");
        printf("INVENTORY DATA MAIN MENU\n\n");
        printf("What do you want to do?\n");
        printf("1. Insert Record\n");
        printf("2. Show Record\n");
        printf("3. Select Data\n");
        printf("4. Delete Record\n");
        printf("5. Update Record\n");
        printf("0. Exit\n\n");
        printf("Your choice: ");
        scanf("%d", &choose);
        
        if(choose == 0){
        	system("cls || clear"); break;
		} else if(choose == 1){
            addRecordMenu();
		} else if(choose == 2){
            
		} else if(choose == 3){
            
		} else if(choose == 4){
            
		} else if(choose == 5){
            
		} else if(choose == 6){
            
		} else if(choose == 7){
            
		}

    
    }
}
