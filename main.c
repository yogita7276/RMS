#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "order.h"
#include "customer.h"
#include "billing.h"

void clearScreen()
{
    system("cls");
}

void printMenu()
{
    printf("\n");
    printf("=========================================================================================================\n");
    printf("                                     Restaurant Management System          \n");
    printf("=========================================================================================================\n");
    printf("1. Add Menu Item\t\t");
    printf("2. Add Customer\t\t\t");
    printf("3. Add Order\n");
    printf("4. Display Menu\t\t\t");
    printf("5. Display Customers\t\t");
    printf("6. Display Orders\n");
    printf("7. Delete Menu Item\t\t");
    printf("8. Delete Customer\t\t");
    printf("9. Delete Order\n");
    printf("10. Print Bill\n");
    printf("11. Exit\n");
    printf("=========================================================================================================\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice;
    MenuItem item;
    Customer customer;
    Order order;
    int id;

    while (1)
    {
        clearScreen();

        printMenu();
        scanf("%d", &choice);
<<<<<<< HEAD
        getchar(); 

        clearScreen();

        switch (choice) {
            case 1:
                printf("\n=========================================================================================================\n");
                do{
                printf("\nEnter item ID: ");
                scanf("%d", &item.id);
                getchar();
                if(itemIdExists(item.id))
                {
                printf("Duplicate ID not allowed. please enter another ID.\n");
                }
                }
                while(itemIdExists(item.id));
                
                printf("Enter item name: ");
                fgets(item.name, sizeof(item.name), stdin);
                item.name[strcspn(item.name, "\n")] = 0;  //
                printf("Enter item price: ");
                scanf("%f", &item.price);
                addMenuItem(item);
                printf("Menu item added successfully!\n");
                printf("=========================================================================================================\n");
                break;
            case 2:
                printf("\n=========================================================================================================\n");
                
                do {
                    printf("\nEnter customer ID: ");
                    scanf("%d", &customer.id);
                    getchar();
                    if (customerIdExists(customer.id)) {
                        printf("Duplicate ID not allowed. Please enter a new customer ID.\n");
                    }
                } while (customerIdExists(customer.id));
                getchar(); 
                printf("Enter customer name: ");
                fgets(customer.name, sizeof(customer.name), stdin);
                customer.name[strcspn(customer.name, "\n")] = 0; 
                printf("Enter customer phone: ");
                fgets(customer.phone, sizeof(customer.phone), stdin);
                customer.phone[strcspn(customer.phone, "\n")] = 0; 
                addCustomer(customer);
                printf("Customer added successfully!\n");
                printf("=========================================================================================================\n");
                break;
            case 3:
                printf("\n=========================================================================================================\n");
                
                do {
                    printf("\nEnter order ID: ");
                    scanf("%d", &order.id);
                    if (orderIdExists(order.id)) {
                        printf("Duplicate ID not allowed. Please enter a new order ID.\n");
                    }
                } while (orderIdExists(order.id));
                do {
                    printf("Enter customer ID: ");
                    scanf("%d", &order.customerId);
                if (!customerIdExists(order.customerId)) {
                    printf("customer ID not found. Please enter a valid customer ID.\n");
                }
            }while (!customerIdExists(order.customerId));

            do{
                printf("Enter item ID: ");
                scanf("%d", &order.itemId);
                if(!itemIdExists(order.itemId))
                {
                    printf("item ID not found please enter a valid item ID.\n");
                }
            }while(!itemIdExists(order.itemId));

                printf("Enter quantity: ");
                scanf("%d", &order.quantity);
                addOrder(order);
                printf("Order added successfully!\n");
                printf("=========================================================================================================\n");
                break;
            case 4:
                printf("\n=========================================================================================================\n");
                displayMenu();
                printf("=========================================================================================================\n");
                break;
            case 5:
                printf("\n=========================================================================================================\n");
                displayCustomers();
                printf("=========================================================================================================\n");
                break;
            case 6:
                printf("\n=========================================================================================================\n");
                displayOrders();
                printf("=========================================================================================================\n");
                break;
            case 7:
                printf("\n=========================================================================================================\n");
                printf("\n\nEnter item ID to delete: ");
                scanf("%d", &id);
                deleteMenuItem(id);
                printf("=========================================================================================================\n");
                break;
            case 8:
                printf("\n=========================================================================================================\n");
                printf("\n\nEnter customer ID to delete: ");
                scanf("%d", &id);
                deleteCustomer(id);
                printf("=========================================================================================================\n");
                break;
            case 9:
                printf("\n=========================================================================================================\n");
                printf("\n\nEnter order ID to delete: ");
                scanf("%d", &id);
                deleteOrder(id);
                printf("=========================================================================================================\n");
                break;
            case 10:
                printf("\n=========================================================================================================\n");
                printf("\n\nEnter order ID to print bill: ");
                scanf("%d", &id);
                printBill(id);
                printf("=========================================================================================================\n");
                printf("\nPress Enter to continue...");
                getchar(); // Waiting for press Enter
                break;
            case 11:
                printf("\nExiting the system. Goodbye!......\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
=======
        getchar(); // getchar is used to consume newline character

        clearScreen();

        switch (choice)
        {
        case 1:
            printf("\n=========================================================================================================\n");
            do
            {
                printf("\nEnter item ID: ");
                scanf("%d", &item.id);
                getchar(); 
                if (itemIdExists(item.id))
                {
                    printf("Duplicate ID not allowed. Please enter a new item ID.\n");
                }
            } while (itemIdExists(item.id));
            printf("Enter item name: ");
            fgets(item.name, sizeof(item.name), stdin);
            item.name[strcspn(item.name, "\n")] = 0; //
            printf("Enter item price: ");
            scanf("%f", &item.price);
            getchar(); 
            addMenuItem(item);
            printf("Menu item added successfully!\n");
            printf("=========================================================================================================\n");
            break;
        case 2:
            printf("\n=========================================================================================================\n");
            do
            {
                printf("\nEnter customer ID: ");
                scanf("%d", &customer.id);
                getchar(); 
                if (customerIdExists(customer.id))
                {
                    printf("Duplicate ID not allowed. Please enter a new customer ID.\n");
                }
            } while (customerIdExists(customer.id));
            printf("Enter customer name: ");
            fgets(customer.name, sizeof(customer.name), stdin);
            customer.name[strcspn(customer.name, "\n")] = 0;
            printf("Enter customer phone: ");
            fgets(customer.phone, sizeof(customer.phone), stdin);
            customer.phone[strcspn(customer.phone, "\n")] = 0;
            addCustomer(customer);
            printf("Customer added successfully!\n");
            printf("=========================================================================================================\n");
            break;
        case 3:
            printf("\n=========================================================================================================\n");
            do
            {
                printf("\nEnter order ID: ");
                scanf("%d", &order.id);
                getchar(); // Consume newline character
                if (orderIdExists(order.id))
                {
                    printf("Duplicate ID not allowed. Please enter a new order ID.\n");
                }
            } while (orderIdExists(order.id));
            do
            {
                printf("Enter customer ID: ");
                scanf("%d", &order.customerId);
                getchar(); // Consume newline character
                if (!customerIdExists(order.customerId))
                {
                    printf("Customer ID not found. Please enter a valid customer ID.\n");
                }
            } while (!customerIdExists(order.customerId));
            do
            {
                printf("\nEnter item ID: ");
                scanf("%d", &order.itemId);
                getchar(); 
                if (!itemIdExists(order.itemId))
                {
                    printf("Item ID not found. Please enter a valid item ID.\n");
                }
            } while (!itemIdExists(order.itemId));
            printf("Enter quantity: ");
            scanf("%d", &order.quantity);
            getchar(); 
            addOrder(order);
            printf("Order added successfully!\n");
            printf("=========================================================================================================\n");
            break;
        case 4:
            printf("\n=========================================================================================================\n");
            displayMenu();
            printf("=========================================================================================================\n");
            break;
        case 5:
            printf("\n=========================================================================================================\n");
            displayCustomers();
            printf("=========================================================================================================\n");
            break;
        case 6:
            printf("\n=========================================================================================================\n");
            displayOrders();
            printf("=========================================================================================================\n");
            break;
        case 7:
            printf("\n=========================================================================================================\n");
            printf("\n\nEnter item ID to delete: ");
            scanf("%d", &id);
            getchar(); // Consume newline character
            deleteMenuItem(id);
            printf("=========================================================================================================\n");
            break;
        case 8:
            printf("\n=========================================================================================================\n");
            printf("\n\nEnter customer ID to delete: ");
            scanf("%d", &id);
            getchar(); // Consume newline character
            deleteCustomer(id);
            printf("=========================================================================================================\n");
            break;
        case 9:
            printf("\n=========================================================================================================\n");
            printf("\n\nEnter order ID to delete: ");
            scanf("%d", &id);
            getchar(); // Consume newline character
            deleteOrder(id);
            printf("=========================================================================================================\n");
            break;
        case 10:
            printf("\n=========================================================================================================\n");
            printf("\n\nEnter order ID to print bill: ");
            scanf("%d", &id);
            getchar(); // Consume newline character
            printBill(id);
            printf("=========================================================================================================\n");
            printf("\nPress Enter to continue...");
            getchar(); // Waiting for our user to press Enter
            break;
        case 11:
            printf("\nExiting the system. Goodbye!......\n");
            return 0;
        default:
            printf("\nInvalid choice. Please try again.\n");
>>>>>>> 911697029e1dec43a4a90c77808e027fd55b4dfc
        }
        printf("\nPress Enter to continue...");
        getchar();
    }

    return 0;
}