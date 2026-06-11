/*
 * Pre-coding questions:
 *
 * Q1: If the user enters 12321, what is 12321 % 10? What digit does that give you?
 *     12321 % 10 = 1. This gives the last (5th) digit of the number.
 *
 * Q2: How would you extract the first digit of a five-digit number using /?
 *     Divide the number by 10000: 12321 / 10000 = 1. Since integer division
 *     truncates, only the ten-thousands digit remains.
 *
 * Q3: Which pairs of digits must match for the number to be a palindrome?
 *     digit1 must equal digit5 (first and last),
 *     digit2 must equal digit4 (second and second-to-last).
 *     digit3 (the middle digit) can be anything.
 */

#include <stdio.h>

int main(void) {
    int number;
    int digit1, digit2, digit3, digit4, digit5;

    printf("Enter a five-digit integer: ");
    scanf("%d", &number);

    /* Extract each digit using / and % only */
    digit1 = number / 10000;          /* ten-thousands place */
    digit2 = (number / 1000) % 10;   /* thousands place     */
    digit3 = (number / 100)  % 10;   /* hundreds place      */
    digit4 = (number / 10)   % 10;   /* tens place          */
    digit5 = number % 10;            /* ones place          */

    /* digit3 is the middle digit; it does not affect palindrome check */
    (void)digit3;

    if (digit1 == digit5 && digit2 == digit4) {
        printf("%d is a palindrome.\n", number);
    } else {
        printf("%d is not a palindrome.\n", number);
    }

    return 0;
}
