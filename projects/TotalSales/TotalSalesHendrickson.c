#include <stdio.h>

#define SALESPEOPLE 4
#define PRODUCTS    5

int main(void) {
    double sales[PRODUCTS][SALESPEOPLE] = {0};
    int salesperson, product;
    double amount;

    printf("Enter sales slips (salesperson product amount), 0 0 0 to quit:\n");

    while (1) {
        scanf("%d %d %lf", &salesperson, &product, &amount);
        if (salesperson == 0 && product == 0 && amount == 0.0)
            break;

        if (salesperson < 1 || salesperson > SALESPEOPLE ||
            product < 1 || product > PRODUCTS || amount < 0) {
            printf("Invalid input, try again.\n");
            continue;
        }

        sales[product - 1][salesperson - 1] += amount;
    }

    /* Print header */
    printf("\n%-10s", "Product");
    for (int sp = 1; sp <= SALESPEOPLE; sp++)
        printf("  SP%-7d", sp);
    printf("  %-10s\n", "Total");

    /* Separator */
    printf("%-10s", "----------");
    for (int sp = 0; sp <= SALESPEOPLE; sp++)
        printf("  ----------");
    printf("\n");

    double productTotals[PRODUCTS]     = {0};
    double spTotals[SALESPEOPLE]       = {0};
    double grandTotal                  = 0.0;

    /* Print each product row */
    for (int p = 0; p < PRODUCTS; p++) {
        printf("%-10d", p + 1);
        double rowTotal = 0.0;

        for (int sp = 0; sp < SALESPEOPLE; sp++) {
            printf("  %9.2f", sales[p][sp]);
            rowTotal      += sales[p][sp];
            spTotals[sp]  += sales[p][sp];
        }

        productTotals[p] = rowTotal;
        grandTotal       += rowTotal;
        printf("  %9.2f\n", rowTotal);
    }

    /* Separator */
    printf("%-10s", "----------");
    for (int sp = 0; sp <= SALESPEOPLE; sp++)
        printf("  ----------");
    printf("\n");

    /* Print column totals */
    printf("%-10s", "Total");
    for (int sp = 0; sp < SALESPEOPLE; sp++)
        printf("  %9.2f", spTotals[sp]);
    printf("  %9.2f\n", grandTotal);

    return 0;
}