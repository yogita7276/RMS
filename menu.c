#include <stdio.h>
#include <string.h>
#include "menu.h"
//#include "order.h"

// Function to check if an item ID exists in the menu
int itemIdExists(int itemId) {
    FILE *file = fopen("menu.txt", "r");
    if (file == NULL) {
        printf("Error opening menu file!\n");
        return 0;
    }

    MenuItem item;
    while (fscanf(file, "%d %49s %f", &item.id, item.name, &item.price) == 3) 
    {
        if (item.id == itemId) {
            fclose(file);
            return 1;  
        }
    }

    fclose(file);
    return 0;  
}

<<<<<<< HEAD
void addMenuItem(MenuItem item) {
    //if (itemIdExists(item.id)) {
     //   printf("item ID not found. Please enter a valid item ID.\n");
     //return;
//}
    FILE *file = fopen("menu.txt", "a"); 
=======
int itemIdExists(int itemId) {
    FILE *file = fopen("menu.txt", "r");
    if (file == NULL) {
        printf("Error opening menu file!\n");
        return 0;
    }
    MenuItem item;
    while (fscanf(file, "%d %49s %f", &item.id, item.name, &item.price) == 3) {
        if (item.id == itemId) {
            fclose(file);
            return 1; // Item ID exists
        }
    }
    fclose(file);
    return 0; // Item ID does not exist
}

// Function to add a menu item to the menu file
void addMenuItem(MenuItem item) {
    FILE *file = fopen("menu.txt", "a");//open in append mode
>>>>>>> 911697029e1dec43a4a90c77808e027fd55b4dfc
    if (file == NULL) {
        printf("Error opening file!\n");
        return; 
    }
    
    fprintf(file, "%d %s %.2f\n", item.id, item.name, item.price);
    fclose(file); 
}

// Function to display all menu items in a table format
void displayMenu() {
    FILE *file = fopen("menu.txt", "r"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return; 
    }
    char line[100]; 
    MenuItem item;

    
    printf("+----+------------------------------+--------+\n");
    printf("| ID | Name                         | Price  |\n");
    printf("+----+------------------------------+--------+\n");

   
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d %49s %f", &item.id, item.name, &item.price);
        printf("| %-2d | %-28s | %-6.2f |\n", item.id, item.name, item.price);
    }


    printf("+----+------------------------------+--------+\n");
    fclose(file); 
}

// Function to delete a menu item by ID
void deleteMenuItem(int itemId) {
    FILE *file = fopen("menu.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[100];
    MenuItem item;
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d %49s %f", &item.id, item.name, &item.price);
        if (item.id != itemId) {
            fprintf(tempFile, "%d %s %.2f\n", item.id, item.name, item.price);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("menu.txt");
    rename("temp.txt", "menu.txt");

    if (found) {
        printf("Menu item deleted successfully!\n");
    } else {
        printf("Menu item ID not found!\n");
    }
}

MenuItem getMenuItemById(int itemId) {
    FILE *file = fopen("menu.txt", "r");
    MenuItem item;
    item.id = -1; 

    if (file == NULL) {
        printf("Error opening menu file!\n");
        return item;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d %49s %f", &item.id, item.name, &item.price);
        if (item.id == itemId) {
            fclose(file);
            return item;
        }
    }

    fclose(file);
    item.id = -1; 
    return item;
}