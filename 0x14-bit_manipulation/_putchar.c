#include <stdio.h>

int a_putchar(int c) {
    FILE *file;
    file = fopen("output.txt", "a");
    if (file == NULL) {
        return EOF;
    }
    putc(c, file);
    fclose(file);
    return c;
}

