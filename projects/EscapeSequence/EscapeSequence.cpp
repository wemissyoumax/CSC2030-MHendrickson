#include <stdio.h>

int main(void)
{
    /* Non-cursor-moving escape sequences: print a literal character */
    puts("=== Escape sequences that print a literal character ===");

    printf("\\'  single quote : \'\n");
    printf("\\\"  double quote : \"\n");
    printf("\\?  question mark: \?\n");
    printf("\\\\  backslash    : \\\n");

    /* Alert (audible or visible bell) */
    printf("\\a  alert (you should hear a beep): \a\n");

    putchar('\n');

    /* Cursor-moving escape sequences: print a character before and after
       so the movement of the cursor is visible */
    puts("=== Escape sequences that move the cursor ===");

    /* \b - backspace: moves the cursor one position to the left */
    printf("\\b  backspace: X\bY (Y overwrites/sits after X moved back)\n");

    /* \n - newline: moves the cursor to the start of the next line */
    printf("\\n  newline: A\nB (B starts on a new line)\n");

    /* \r - carriage return: moves the cursor to the start of current line */
    printf("\\r  carriage return: 12345\rXY (XY overwrites the start)\n");

    /* \t - horizontal tab: moves the cursor to the next tab stop */
    printf("\\t  tab: A\tB (a gap sits between A and B)\n");

    return 0;
}