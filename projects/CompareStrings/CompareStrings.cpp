#include <stdio.h>
#include <string.h>

#define SIZE 100

int main(void)
{
    char string1[SIZE]; /* first string to compare */
    char string2[SIZE]; /* second string to compare */
    size_t n;           /* number of characters to compare */
    int result;         /* value returned by strncmp */

    /* prompt for and read the two strings */
    printf("Enter the first string: ");
    fgets(string1, SIZE, stdin);
    string1[strcspn(string1, "\n")] = '\0'; /* strip trailing newline */

    printf("Enter the second string: ");
    fgets(string2, SIZE, stdin);
    string2[strcspn(string2, "\n")] = '\0'; /* strip trailing newline */

    /* prompt for and read the number of characters to compare */
    printf("Enter the number of characters to compare: ");
    scanf("%zu", &n);

    /* compare the first n characters of the two strings */
    result = strncmp(string1, string2, n);

    /* display the result of the comparison */
    printf("\nComparing the first %zu character(s):\n", n);
    printf("\"%s\" ", string1);

    if (result < 0) {
        printf("is less than ");
    }
    else if (result == 0) {
        printf("is equal to ");
    }
    else {
        printf("is greater than ");
    }

    printf("\"%s\"\n", string2);
    printf("(strncmp returned %d)\n", result);

    return 0;
}