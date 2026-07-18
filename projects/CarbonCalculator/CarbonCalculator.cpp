/*
 * carbon_footprint.c
 *
 * Calculates the annual carbon footprint of a building, a car, or a
 * bicycle using an array of function pointers. Each calculation
 * function takes no arguments and returns void, per the exercise.
 *
 * Emission factors (U.S. EPA and European Cyclists' Federation):
 *   Electricity:  0.92 lb CO2 per kWh  (~0.417 kg)
 *   Natural gas:  11.7 lb CO2 per therm (~5.3 kg)
 *   Gasoline:     8.887 kg CO2 per gallon burned
 *   Bicycling:    21 g CO2e per km (~33.8 g per mile), from the extra
 *                 food production needed to fuel the rider
 */

#include <stdio.h>

#define KG_PER_KWH        0.417   /* electricity, kg CO2 per kWh        */
#define KG_PER_THERM      5.3     /* natural gas, kg CO2 per therm      */
#define KG_PER_GALLON     8.887   /* gasoline, kg CO2 per gallon        */
#define KG_PER_BIKE_MILE  0.0338  /* food-related emissions per mile    */

void buildingFootprint(void);
void carFootprint(void);
void bicycleFootprint(void);
void flushInput(void);

int main(void)
{
    /* array of pointers to functions that take no arguments and return void */
    void (*footprintFunctions[3])(void) =
        { buildingFootprint, carFootprint, bicycleFootprint };

    int choice; /* menu selection */

    while (1) {
        puts("\nCarbon Footprint Calculator");
        puts("---------------------------");
        puts("0 - Building");
        puts("1 - Car");
        puts("2 - Bicycle");
        puts("3 - Quit");
        printf("%s", "Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            flushInput();
            puts("Invalid input. Please enter a number from 0 to 3.");
            continue;
        }

        if (choice == 3) {
            puts("Goodbye!");
            break;
        }

        if (choice >= 0 && choice <= 2) {
            (*footprintFunctions[choice])(); /* call the chosen function */
        }
        else {
            puts("Invalid choice. Please enter a number from 0 to 3.");
        }
    }

    return 0;
}

/* carbon footprint of a building from annual electricity and gas use */
void buildingFootprint(void)
{
    double kwh;    /* electricity used per year, in kWh    */
    double therms; /* natural gas used per year, in therms */

    puts("\n--- Building Carbon Footprint ---");
    printf("%s", "Enter annual electricity use (kWh): ");
    scanf("%lf", &kwh);
    printf("%s", "Enter annual natural gas use (therms): ");
    scanf("%lf", &therms);

    double kgCO2 = kwh * KG_PER_KWH + therms * KG_PER_THERM;

    printf("The building's carbon footprint is %.2f kg CO2 per year "
           "(%.2f metric tons).\n", kgCO2, kgCO2 / 1000.0);
}

/* carbon footprint of a car from annual miles driven and fuel economy */
void carFootprint(void)
{
    double miles; /* miles driven per year        */
    double mpg;   /* fuel economy in miles/gallon */

    puts("\n--- Car Carbon Footprint ---");
    printf("%s", "Enter miles driven per year: ");
    scanf("%lf", &miles);
    printf("%s", "Enter fuel economy (miles per gallon): ");
    scanf("%lf", &mpg);

    if (mpg <= 0.0) {
        puts("Fuel economy must be greater than zero.");
        return;
    }

    double gallons = miles / mpg;
    double kgCO2 = gallons * KG_PER_GALLON;

    printf("The car burns %.2f gallons of gasoline per year.\n", gallons);
    printf("The car's carbon footprint is %.2f kg CO2 per year "
           "(%.2f metric tons).\n", kgCO2, kgCO2 / 1000.0);
}

/* carbon footprint of a bicycle from annual miles ridden */
void bicycleFootprint(void)
{
    double miles; /* miles ridden per year */

    puts("\n--- Bicycle Carbon Footprint ---");
    printf("%s", "Enter miles ridden per year: ");
    scanf("%lf", &miles);

    double kgCO2 = miles * KG_PER_BIKE_MILE;

    puts("A bicycle burns no fuel; its only emissions come from the");
    puts("extra food the rider eats to power the ride.");
    printf("The bicycle's carbon footprint is %.2f kg CO2 per year.\n", kgCO2);
}

/* discard the rest of the current input line after a bad scanf */
void flushInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        ; /* discard */
    }
}