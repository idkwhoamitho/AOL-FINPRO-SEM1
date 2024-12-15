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
