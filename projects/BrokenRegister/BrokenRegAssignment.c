#include <stdio.h>

int main() {
    float price = 4.99;
    int quantity;
    float total;

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    total = price * quantity;
    printf("Total: %.2f\n", total);

    return 0;
}