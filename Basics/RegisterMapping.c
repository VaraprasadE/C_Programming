#include <stdio.h>
#include <stdint.h>
#define HW_REGISTER_ADR ((volatile uint32_t *)0x40001000)
void configure_hardware(void);
int main()
{
    while(1){
      configure_hardware();  
    }
    
    return 0;
}


// Write your code here
void configure_hardware(void) {
    // 1. Define the Register Pointer
    
    // 2. Set Bit 5
    *HW_REGISTER_ADR |= (1<<5);
    
    // 3. Clear Bit 3
    *HW_REGISTER_ADR &= ~(1<<3);
    
    // 4. Wait for Bit 0 to be 1
    while ( (*HW_REGISTER_ADR & (1 << 0)) == 0 ) {
            // Optional: Do nothing, just wait.
            // In real code, you might add a timeout counter here to avoid hanging forever.
    }

    printf("Hardware Ready!\n");
}
