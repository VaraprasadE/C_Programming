#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 5

typedef struct circularBuffer {
    int buffer[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} circularBuffer;

circularBuffer trainBuffer = {0};

// No overwriting of data in circular buffer, so we check if the buffer is full before pushing new element
bool pushCircularBufferNoOverwrite(circularBuffer *cb, int element){
    if(cb->count == BUFFER_SIZE){
       printf("Buffer is full\n");
       return false;
    }
    cb->buffer[cb->head] = element;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count++;
    return true;
}

int popCircularBufferNoOverwrite(circularBuffer *cb){
    if(cb->count == 0){
       printf("Buffer is Empty\n");
       return -1;
    }
    int element = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;
    return element;
}

// Overwriting of data in circular buffer, so we push new element even if the buffer is full, and overwrite the oldest element
void pushCircularBufferOverwrite(circularBuffer *cb, int element){
    if(cb->count == BUFFER_SIZE){
       printf("Buffer is full, overwriting oldest element\n");
       cb->tail = (cb->tail + 1) % BUFFER_SIZE; // Move tail to next position to overwrite the oldest element
    } else {
       cb->count++;
    }
    cb->buffer[cb->head] = element;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
}

int popCircularBufferOverwrite(circularBuffer *cb){
    if(cb->count == 0){
       printf("Buffer is Empty\n");
       return -1;
    }
    int element = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;
    return element;
}

int main(){
    // pushCircularBufferNoOverwrite(&trainBuffer, 1);
    // pushCircularBufferNoOverwrite(&trainBuffer, 2);
    // pushCircularBufferNoOverwrite(&trainBuffer, 3);
    // pushCircularBufferNoOverwrite(&trainBuffer, 4);
    // pushCircularBufferNoOverwrite(&trainBuffer, 5);
    // pushCircularBufferNoOverwrite(&trainBuffer, 6); // This will show buffer is full
    // printf("Popped element: %d\n", popCircularBufferNoOverwrite(&trainBuffer)); // Output will be 1
    // printf("Popped element: %d\n", popCircularBufferNoOverwrite(&trainBuffer)); // Output will be 2
    // printf("Popped element: %d\n", popCircularBufferNoOverwrite(&trainBuffer)); // Output will be 3
    // printf("Popped element: %d\n", popCircularBufferNoOverwrite(&trainBuffer)); // Output will be 4
    // printf("Popped element: %d\n", popCircularBufferNoOverwrite(&trainBuffer)); // Output will be 5
    // printf("Popped element: %d\n", popCircularBufferNoOverwrite(&trainBuffer)); // This will show buffer is empty
    printf("Testing circular buffer with overwriting:\n");
    pushCircularBufferOverwrite(&trainBuffer, 1);
    pushCircularBufferOverwrite(&trainBuffer, 2);
    pushCircularBufferOverwrite(&trainBuffer, 3);
    pushCircularBufferOverwrite(&trainBuffer, 4);
    pushCircularBufferOverwrite(&trainBuffer, 5);
    pushCircularBufferOverwrite(&trainBuffer, 6); // This will overwrite the oldest element
    printf("Popped element: %d\n", popCircularBufferOverwrite(&trainBuffer)); // Output will be 2
    printf("Popped element: %d\n", popCircularBufferOverwrite(&trainBuffer));
    printf("Popped element: %d\n", popCircularBufferOverwrite(&trainBuffer));
    printf("Popped element: %d\n", popCircularBufferOverwrite(&trainBuffer));
    printf("Popped element: %d\n", popCircularBufferOverwrite(&trainBuffer)); // Output will be 6
    printf("Popped element: %d\n", popCircularBufferOverwrite(&trainBuffer)); // This will show buffer is empty
    return 0;
   
}