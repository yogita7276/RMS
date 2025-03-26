#include <stdio.h>
#include <string.h>
#include "order.h"
#include "menu.h"
#include "customer.h"
<<<<<<< HEAD

=======
>>>>>>> 911697029e1dec43a4a90c77808e027fd55b4dfc

float getItemPrice(int itemId) {
    FILE *file = fopen("menu.txt", "r"); 
    if (file == NULL) {
        printf("Error opening menu file!\n");
        return -1; 
    }
    char line[100];
    MenuItem item;
    
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d %49s %f", &item.id, item.name, &item.price);
        
        if (item.id == itemId) {
            fclose(file);
            return item.price;
        }
    }
    fclose(file);
    return -1; 
}

<<<<<<< HEAD

=======
// Function to check if an order ID already exists
>>>>>>> 911697029e1dec43a4a90c77808e027fd55b4dfc
int orderIdExists(int orderId) {
    FILE *file = fopen("orders.txt", "r");
    if (file == NULL) {
        printf("Error opening orders file!\n");
        return 0;
    }
    Order order;
    while (fscanf(file, "%d %d %d %d %f", &order.id, &order.customerId, &order.itemId, &order.quantity, &order.totalPrice) == 5) {
        if (order.id == orderId) {
            fclose(file);
<<<<<<< HEAD
            return 1; 
        }
    }
    fclose(file);
    return 0; 
}



void addOrder(Order order) {
    if (orderIdExists(order.id)) {
        printf("Duplicate ID not allowed. Please enter a new order ID.\n");

        return;
    }
if (!customerIdExists(order.customerId)) {
        printf("customer ID not found. Please enter a valid customer ID.\n");
     return;
}
=======
            return 1; // Order ID exists
        }
    }
    fclose(file);
    return 0; // Order ID does not exist
}

// Function to add an order
void addOrder(Order order) {
    if (orderIdExists(order.id)) {
        printf("Duplicate ID not allowed. Please enter a new order ID.\n");
        return;
    }

    if (!customerIdExists(order.customerId)) {
        printf("Customer ID not found. Please enter a valid customer ID.\n");
        return;
    }
    
>>>>>>> 911697029e1dec43a4a90c77808e027fd55b4dfc
    float itemPrice = getItemPrice(order.itemId); 
    if (itemPrice == -1) {
        printf("Item ID not found!\n");
        getchar();
        return;  
    }
    
    if (order.quantity <= 0) {
        printf("Invalid quantity!\n");
        return;   
    }

<<<<<<< HEAD
    
=======
    // Calculate the total price
>>>>>>> 911697029e1dec43a4a90c77808e027fd55b4dfc
    order.totalPrice = itemPrice * order.quantity;

    FILE *file = fopen("orders.txt", "a"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return; 
    }
    
    fprintf(file, "%d %d %d %d %.2f\n", order.id, order.customerId, order.itemId, order.quantity, order.totalPrice);
   fclose(file);
}

    


void displayOrders() {
    FILE *file = fopen("orders.txt", "r"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return; 
    
    }
    Order order;

    // Print the table header
    printf("+----------+-------------+-------------+----------+-------------+\n");
    printf("| Order ID | Customer ID | Menu Item ID| Quantity | Total Price |\n");
    printf("+----------+-------------+-------------+----------+-------------+\n");

    
    while (fscanf(file, "%d %d %d %d %f", &order.id, &order.customerId, &order.itemId, &order.quantity, &order.totalPrice) == 5) {
        printf("| %-8d | %-11d | %-11d | %-8d | %-11.2f |\n", order.id, order.customerId, order.itemId, order.quantity, order.totalPrice);
    }

    
    printf("+----------+-------------+-------------+----------+-------------+\n");
    fclose(file);
}

// Function to delete an order by ID
void deleteOrder(int orderId) {
    FILE *file = fopen("orders.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[100];
    Order order;
    int found = 0;

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d %d %d %d %f", &order.id, &order.customerId, &order.itemId, &order.quantity, &order.totalPrice);
        // Write the line to the temporary file if the order ID does not match
        if (order.id != orderId) {
            fprintf(tempFile, "%d %d %d %d %.2f\n", order.id, order.customerId, order.itemId, order.quantity, order.totalPrice);
        } else {
            found = 1; // Set the flag if the order ID is found
        }
    }

    fclose(file); // Close the original file
    fclose(tempFile); // Close the temporary file

    remove("orders.txt"); // Delete the original file
    rename("temp.txt", "orders.txt"); // Rename the temporary file to the original file name

    if (found) {
        printf("Order deleted successfully!\n");
    } else {
        printf("Order ID not found!\n");
    }
}

// Function to get an order by ID
Order getOrderById(int orderId) {
    FILE *file = fopen("orders.txt", "r");
    Order order;
    order.id = -1; 

    if (file == NULL) {
        printf("Error opening orders file!\n");
        return order;
    }

    // Read each line from the file
    while (fscanf(file, "%d %d %d %d %f", &order.id, &order.customerId, &order.itemId, &order.quantity, &order.totalPrice) == 5) {
        // Return the order if the ID matches
        if (order.id == orderId) {
            fclose(file);
            return order;
        }
    }

<<<<<<< HEAD
    fclose(file);
    order.id = -1; 
=======
    fclose(file); // Close the file
    order.id = -1; // Set to invalid ID if not found
>>>>>>> 911697029e1dec43a4a90c77808e027fd55b4dfc
    return order;
}