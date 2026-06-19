#include <stdio.h>

int main(void) {
    int accountNum1, accountNum2, accountNum3;
    double creditLimit1, creditLimit2, creditLimit3;
    double balance1, balance2, balance3;
    double newLimit1, newLimit2, newLimit3;

    printf("Enter account number, credit limit, and balance for customer 1: ");
    scanf("%d %lf %lf", &accountNum1, &creditLimit1, &balance1);

    printf("Enter account number, credit limit, and balance for customer 2: ");
    scanf("%d %lf %lf", &accountNum2, &creditLimit2, &balance2);

    printf("Enter account number, credit limit, and balance for customer 3: ");
    scanf("%d %lf %lf", &accountNum3, &creditLimit3, &balance3);

    newLimit1 = creditLimit1 / 2.0;
    newLimit2 = creditLimit2 / 2.0;
    newLimit3 = creditLimit3 / 2.0;

    printf("\n%-15s %-15s %-15s %-15s\n",
           "Account", "Old Limit", "New Limit", "Balance");
    printf("%-15d %-15.2f %-15.2f %-15.2f\n",
           accountNum1, creditLimit1, newLimit1, balance1);
    printf("%-15d %-15.2f %-15.2f %-15.2f\n",
           accountNum2, creditLimit2, newLimit2, balance2);
    printf("%-15d %-15.2f %-15.2f %-15.2f\n",
           accountNum3, creditLimit3, newLimit3, balance3);

    printf("\nCustomers who exceeded their new credit limit:\n");

    int anyExceeded = 0;

    if (balance1 > newLimit1) {
        printf("  Account %d: balance $%.2f exceeds new limit $%.2f\n",
               accountNum1, balance1, newLimit1);
        anyExceeded = 1;
    }
    if (balance2 > newLimit2) {
        printf("  Account %d: balance $%.2f exceeds new limit $%.2f\n",
               accountNum2, balance2, newLimit2);
        anyExceeded = 1;
    }
    if (balance3 > newLimit3) {
        printf("  Account %d: balance $%.2f exceeds new limit $%.2f\n",
               accountNum3, balance3, newLimit3);
        anyExceeded = 1;
    }

    if (!anyExceeded) {
        printf("  None\n");
    }

    return 0;
}
