#include <stdio.h>

int main() 
{
    int option, qty, total = 0;
    char cont = 'y';

    // To store orders
    int orderItem[50];
    int orderQty[50];
    int orderCount = 0;

    // Menu item names
    char names[5][20] = {
        "Dosa",
        "Idli",
        "Tea",
        "Masala Dosa",
        "Vada"
    };

    // Prices
    int prices[5] = {40, 30, 15, 50, 25};

    printf("=============================================\n");
    printf("            WELCOME TO HOTEL FOODIES\n");
    printf("=============================================\n");

    while (cont == 'y' || cont == 'Y')
    {
        // MENU
        printf("\n-------------- HOTEL MENU ------------------\n");
        for (int i = 0; i < 5; i++)
        {
            printf("%d. %-15s Rs. %d\n", i + 1, names[i], prices[i]);
        }
        printf("--------------------------------------------\n");

        // OPTION INPUT
        printf("Enter your option (1-5): ");
        scanf("%d", &option);

        if (option < 1 || option > 5)
        {
            printf("Invalid choice! Please select 1–5.\n");
            continue;
        }

        // QUANTITY
        printf("Enter quantity for %s: ", names[option - 1]);
        scanf("%d", &qty);

        if (qty <= 0)
        {
            printf("Quantity must be at least 1.\n");
            continue;
        }

        // Save the order
        orderItem[orderCount] = option - 1;
        orderQty[orderCount] = qty;
        orderCount++;

        int cost = prices[option - 1] * qty;
        total += cost;

        printf("%d x %s added to order. Amount = Rs. %d\n", qty, names[option - 1], cost);

        // Continue?
        printf("\nDo you want to order another item? (y/n): ");
        scanf(" %c", &cont);
    }

    // FINAL BILL
    printf("\n================ FINAL BILL =================\n");
    if (orderCount == 0)
    {
        printf("No items ordered.\n");
    }
    else
    {
        printf("%-5s %-15s %-8s %-10s\n", "No.", "Item", "Qty", "Amount");
        printf("--------------------------------------------\n");

        for (int i = 0; i < orderCount; i++)
        {
            int idx = orderItem[i];
            int q = orderQty[i];
            int amount = prices[idx] * q;

            printf("%-5d %-15s %-8d %-10d\n", i + 1, names[idx], q, amount);
        }

        printf("--------------------------------------------\n");
        printf("Total Amount: Rs. %d\n", total);
    }
    printf("============================================\n");

    // PAYMENT
    int pay;
    printf("\nSelect Payment Method:\n");
    printf("1. Cash / Card\n");
    printf("2. Online (QR Scan)\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &pay);

    if (pay == 1)
    {
        printf("\nYou selected Cash/Card.\n");
        printf("Please wait, our staff will assist you.\n");
    }
    else if (pay == 2)
    {
        printf("\nYou selected Online Payment.\n");
        printf("Please scan the QR code at your table.\n");
    }
    else
    {
        printf("\nInvalid payment choice.\nPlease visit reception for assistance.\n");
    }

    printf("\n-------- THANK YOU FOR VISITING HOTEL FOODIES --------\n");

    return 0;
}
