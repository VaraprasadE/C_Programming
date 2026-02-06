#include <stdio.h>


void arrayPointerDemo() {
    int arr[] = {10, 20, 30, 40, 50};
    int *p1 = arr;
    p1++; // Now p1 points to arr[1] which is 20
    int a = *(p1+2); // This will access arr[3] which is 40
    printf("Value at p1: %d\n", *(p1+2));

    int arr2[10];
    int *p1_2 = &arr2[2];
    int *p2 = &arr2[5];
    printf("Difference between pointers: %ld\n", p2 - p1_2); // Output will be 3
}

void pointerSizeDemo() {
    // Char pointer demonstration
    char a = 'A';
    char *str = &a;
    printf("Size char pointer: %zu bytes\n", sizeof(str)); // Output will be 8 bytes on a 64-bit system
    // Note: The size of a pointer depends on the computer architecture.
    // On a 16-bit system, the size of a pointer (including char*) is typically 2 bytes.
    printf("(On a 16-bit system, size of char pointer is typically 2 bytes.)\n");
    printf("Value of a: %c\n", *str); // Output will be 'A'
}

void intPointerArithmeticDemo() {
    int *ptr = NULL;
    int x = 10;
    ptr = &x;

    // Examples of pointer arithmetic with increment operators
    x = *ptr++;
    printf("Value of x: %d\n", x); // Output will be 10
    x = *++ptr;
    printf("Value of x: %d\n", x); // Undefined behavior
    x = ++*ptr;
    printf("Value of x: %d\n", x); // Output will be 11
    x = (*ptr)++;
    printf("Value of x: %d\n", x); // Output will be 10
}

int main() {
    arrayPointerDemo();
    pointerSizeDemo();
    intPointerArithmeticDemo();
}