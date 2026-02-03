#include <stdio.h>
#include <stdbool.h>

void printBinary(char n) {
    printf("\n");
    for(int i=sizeof(n)*8-1; i>=0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
}

char reverseByte(char n) {
    char result = 0;
    for(int i = 7; i>= 0; i--) {
        if ((n >> i) & 1) {
            result |= (1 << 7-i); 
        }
    }
    return result;
}

unsigned char swapNibbles(unsigned char x){
    return (x >> 4) | (x << 4);
}

int swapIntegers(int num) {
    return ((num >> 24) & 0xff) |      // Move byte 3 to byte 0
           ((num << 8) & 0xff0000) |   // Move byte 1 to byte 2
           ((num >> 8) & 0xff00) |     // Move byte 2 to byte 1
           ((num << 24) & 0xff000000); // Move byte 0 to byte 3
}

void swapTwoIntegersNoExtraVariable(int* ptr1, int* ptr2) {
    // Check if pointers are the same (swapping a variable with itself)
    if (ptr1 == ptr2) {
        return;
    }
    *ptr1 = *ptr1 ^ *ptr2; // num1 = 5 ^ 10 = 15
    *ptr2 = *ptr1 ^ *ptr2; // num2 = 15 ^ 10 = 5 (original num1)
    *ptr1 = *ptr1 ^ *ptr2; // num1 = 15 ^ 5 = 10 (original num2)
}

bool isPowerOfTwo(int n) {
    // Check if n is positive and has only one bit set
    return (n > 0) && ((n & (n - 1)) == 0);
}

void check_endianness() {
    unsigned int num = 1; 
    char *ptr = (char*)&num; 
    
    // In Little Endian, the "1" is stored in the first byte (lowest address).
    // In Big Endian, the "1" is stored in the last byte.
    if (*ptr == 1) {
        printf("\n Little Endian\n"); // Intel/ARM (usually)
    } else {
        printf("\n Big Endian\n");    // Network protocols/Old PowerPC
    }
}

int main() {
    char num = 10; // 00001010 in binary
    num |= (1<<2); // Set the 3rd bit
    printBinary(num); // Output: 00001010 | 00000100 = 00001110

    num &= ~(1<<2); // Clear the 3rd bit
    printBinary(num); // Output: 00001110 & 11111011 = 00001010

    num ^= (1<<3); // Toggle the 4th bit
    printBinary(num); // Output: 00001010 ^ 00001000 = 00000010

    if (num & (1<<1)) { // Check if the 2nd bit is set
        printf("\n 2nd bit is set\n");
    } else {
        printf("\n 2nd bit is not set\n");
    }

    char num1 = 0x62; // 01100010 in binary
    char reversed = reverseByte(num1);
    printBinary(reversed); // Output: 01100010 reversed = 01000110
    char swapped = swapNibbles((unsigned char)num1);
    printBinary(swapped); // Output: 01100010 swapped nibbles = 00100110
    check_endianness();

    int intNum = 0x12345678;
    int swappedInt = swapIntegers(intNum);
    printf("\nOriginal: 0x%x, Swapped: 0x%x\n", intNum, swappedInt);

    int a = 5, b = 10;
    printf("\n Before Swap: a = %d, b = %d\n", a, b);
    swapTwoIntegersNoExtraVariable(&a, &b);
    printf("\nAfter Swap: a = %d, b = %d\n", a, b);

    return 0;
}