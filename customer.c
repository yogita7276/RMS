#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"

<<<<<<< HEAD
=======


>>>>>>> 911697029e1dec43a4a90c77808e027fd55b4dfc
int customerIdExists(int customerId) {
    FILE *file = fopen("customers.txt", "r");
    if (file == NULL) {
        printf("Error opening customers file!\n");
        return 0;
    }
    Customer customer;
    while (fscanf(file, "%d|%49[^|]|%14[^\n]", &customer.id, customer.name, customer.phone) == 3) {
        if (customer.id == customerId) {
            fclose(file);
<<<<<<< HEAD
            return 1; 
        }
    }
    fclose(file);
    return 0; 
}
// Function to add a customer to the customers file
void addCustomer(Customer customer) {
    if (customerIdExists(customer.id)) {
        printf("Duplicate ID not allowed. Please enter a new customer ID.\n");
    return;
}
    FILE *file = fopen("customers.txt", "a"); 
=======
            return 1; // Customer ID exists
        }
    }
    fclose(file);
    return 0; // Customer ID does not exist
}


// Function to add a customer to the customers file
void addCustomer(Customer customer) {

    if (customerIdExists(customer.id)) {
        printf("Duplicate ID not allowed. Please enter a new customer ID.\n");
        return;
    }
    
    FILE *file = fopen("customers.txt", "a"); // Open the customers file in append mode
>>>>>>> 911697029e1dec43a4a90c77808e027fd55b4dfc
    if (file == NULL) {
        printf("Error opening file!\n");
        return; 
        getchar();
    }

    fprintf(file, "%d|%s|%s\n", customer.id, customer.name, customer.phone);
    fclose(file); 
}

// Function to display all customers
void displayCustomers() {
    FILE *file = fopen("customers.txt", "r"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return; 
    }

    char line[150]; 
    Customer customer;

    
    printf("+----+------------------------------+---------------+\n");
    printf("| ID | Name                         | Phone         |\n");
    printf("+----+------------------------------+---------------+\n");

    // Read each line from the file and print the customer details
    while (fgets(line, sizeof(line), file)) {
        
        line[strcspn(line, "\n")] = 0;

        
        char *token = strtok(line, "|");
        if (token) customer.id = atoi(token); 

        token = strtok(NULL, "|");
        if (token) strncpy(customer.name, token, sizeof(customer.name) - 1); 
        customer.name[sizeof(customer.name) - 1] = '\0'; 

        token = strtok(NULL, "|");
        if (token) strncpy(customer.phone, token, sizeof(customer.phone) - 1); 
        customer.phone[sizeof(customer.phone) - 1] = '\0'; 

        
        printf("| %-2d | %-28s | %-13s |\n", customer.id, customer.name, customer.phone);
    }


    printf("+----+------------------------------+---------------+\n");
    fclose(file); 
}

// Function to delete a customer by ID
void deleteCustomer(int customerId) {
    FILE *file = fopen("customers.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[150];
    Customer customer;
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d|%49[^|]|%14[^\n]", &customer.id, customer.name, customer.phone);
        if (customer.id != customerId) {
            fprintf(tempFile, "%d|%s|%s\n", customer.id, customer.name, customer.phone);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("customers.txt");
    rename("temp.txt", "customers.txt");

    if (found) {
        printf("Customer deleted successfully!\n");
    } else {
        printf("Customer ID not found!\n");
    }
}

Customer getCustomerById(int customerId) {
    FILE *file = fopen("customers.txt", "r");
    Customer customer;
    customer.id = -1; 

    if (file == NULL) {
        printf("Error opening customers file!\n");
        return customer;
    }

    char line[150];
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d|%49[^|]|%14[^\n]", &customer.id, customer.name, customer.phone);
        if (customer.id == customerId) {
            fclose(file);
            return customer;
        }
    }

    fclose(file);
    customer.id = -1; 
    return customer;
}
