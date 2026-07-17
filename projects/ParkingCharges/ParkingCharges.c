#include <stdio.h>
#include <math.h>

double calculateCharges(double hours) {
    double charge;

    if (hours <= 3.0) {
        charge = 2.00;
    } else {
        double extraHours = ceil(hours - 3.0);
        charge = 2.00 + extraHours * 0.50;
    }

    if (charge > 10.00) {
        charge = 10.00;
    }

    return charge;
}

int main(void) {
    double hours[3], charges[3];
    double totalHours = 0.0, totalCharges = 0.0;

    for (int i = 0; i < 3; i++) {
        printf("Enter hours parked for car %d: ", i + 1);
        scanf("%lf", &hours[i]);
        charges[i] = calculateCharges(hours[i]);
        totalHours += hours[i];
        totalCharges += charges[i];
    }

    printf("\n%-6s %-8s %s\n", "Car", "Hours", "Charge");
    for (int i = 0; i < 3; i++) {
        printf("%-6d %-8.1f %.2f\n", i + 1, hours[i], charges[i]);
    }
    printf("%-6s %-8.1f %.2f\n", "TOTAL", totalHours, totalCharges);

    return 0;
}