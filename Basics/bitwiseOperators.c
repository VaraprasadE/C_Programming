#include <stdio.h>

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

void check_endianness() {
    unsigned int num = 1; 
    char *ptr = (char*)&num; 
    
    // In Little Endian, the "1" is stored in the first byte (lowest address).
    // In Big Endian, the "1" is stored in the last byte.
    if (*ptr == 1) {
        printf("Little Endian\n"); // Intel/ARM (usually)
    } else {
        printf("Big Endian\n");    // Network protocols/Old PowerPC
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

    return 0;
}