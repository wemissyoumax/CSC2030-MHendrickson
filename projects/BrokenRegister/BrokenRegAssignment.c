#include <stdio.h>

int main() {
    float price = 4.99;
    int quantity;
    float total;

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    total = price * quantity;
    if(quantity > 10) {
        total *= 0.9; // Apply a 10% discount for bulk purchases
        printf("Bulk discount applied!\n");
    }
    printf("Total: %.2f\n", total);

    return 0;
}