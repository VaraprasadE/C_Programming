/*
EASY QUESTIONS

    1. Check if the nth bit is set.
    2. Set the nth bit of a number.
    3. Clear the nth bit of a number.
    4. Toggle the nth bit of a number.
    5. Count number of set bits.
    6. Check if a number is power of 2.
    7. Swap two numbers using XOR.

MEDIUM QUESTIONS

    1. Find first set bit in a number.
    2. Find last set bit in a number.
    3. Reverse bits of an 8-bit number.
    4. Swap even and odd bits.
    5. Check if a number has only one bit set.
    6. Clear all bits from MSB to nth bit.
    7. Extract a bit field from register.

HARD QUESTIONS

    1. Reverse bits of a 32-bit integer.
    2. Find two non-repeating elements.
    3. Find the missing number using XOR.
    4. Determine if a number is odd without using %.
    5. Count set bits using Brian Kernighan's Algo.
    6. Swap two bit fields inside a number.
    7. Reverse bits using bit masks (0x55, 0x33, 0x0F).
*/

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/************************* Level 1 ***************************/
// 1. Check if the nth bit is set.
bool isNthbitSet(uint16_t *reg, int bit){
     if((*reg >> bit) & 1){
        return true;
     }
     else{
        return false;
     }
}

//  2. Set the nth bit of a number.
void setNthBit(uint16_t *reg, int bit){
    *reg |= (1 << bit);
}

// 3. Clear the nth bit of a number.
void clearNthBit(uint16_t *reg, int bit){
    *reg &= ~(1 << bit);
}

// 4. Toggle the nth bit of a number.
void toggleNthBit(uint16_t *reg, int bit){
    *reg ^= (1 << bit);
}

// 5. Count number of set bits.
int countSetBits(uint16_t reg){
    int setCount = 0;
    // Using loop looking for the each bit
    /*
    for(int i=0; i<= sizeof(uint16_t)*8-1; i++){
        if((reg >> i) & 1){
            setCount++;
        }
    }
    */

    while(reg > 0){
        setCount++;
        reg &= reg-1; //Brain Karnighan's
    }
    return setCount;
}

// 6. Check if a number is power of 2.
bool isPowerTwo(uint16_t reg){
    if((reg > 0) && (reg &= (reg - 1) == 0)){ //Brain Karnighan's used
        return true;
    }
    return false;
}

// 7. Swap two numbers using XOR.
void swapNumberXor(int *num1, int *num2){
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}
/************************* Level 1 ***************************/

/************************* Level 2 ***************************/

/************************* Level 2 ***************************/


int main(){
    /************************* Level 1 ***************************/
    int bit = 3;
    int setCount = 0;
    uint16_t IO_REGISTER = 0xFFFF;
    if(isNthbitSet(&IO_REGISTER, bit)){
        printf("Bit-%d is set\n",bit);
    }

    clearNthBit(&IO_REGISTER, bit);
    printf("Bit clear IO_REGISTER :%d\n", IO_REGISTER);

    setNthBit(&IO_REGISTER, bit);
    printf("Bit Set IO_REGISTER :%d\n", IO_REGISTER);

    toggleNthBit(&IO_REGISTER, bit);
    printf("Toogle IO_REGISTER :%d\n", IO_REGISTER);

    setCount = countSetBits(IO_REGISTER);
    printf("Number of Set Bits in IO_REGISTER: %d\n", setCount);

    if(isPowerTwo(IO_REGISTER)){
        printf("IO_REG value is Power of 2 \n");
    }else{
        printf("IO_REG value is not Power of 2 \n");
    }

    int a=10, b=20;
    swapNumberXor(&a, &b);
    printf("a = %d, b = %d\n", a,b);

    /************************* Level 2 ***************************/

}
