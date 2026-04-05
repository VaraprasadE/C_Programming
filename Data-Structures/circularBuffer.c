#include<stdio.h>
#include<stdbool.h>

#define BUFFER_SIZE 8          // Buffer Size should be 2 power value
#define MASK (BUFFER_SIZE - 1)

typedef struct circularBuffer{
	int buffer[BUFFER_SIZE];
	int head;
	int tail;
} circularBuffer;

bool pushBuffer(circularBuffer *cb, int *val){
	if(((cb->head + 1) & MASK) == cb->tail){
		printf("Buffer Full \n");
		return 0;
	}
	cb->buffer[cb->head] = *val;
	cb->head = (cb->head + 1) & MASK;
	return 1;
}

int popBuffer(circularBuffer *cb){
	if(cb->head == cb->tail){
		printf("Buffer Empty \n");
		return 0;
	}
	int val = cb->buffer[cb->tail];
	cb->tail = (cb->tail + 1) & MASK;
	return val;
}

void initBuffer(circularBuffer *cb){
	cb->head = 0;
	cb->tail = 0;
}

void main(){
	circularBuffer cb;
	initBuffer(&cb);
	
	for(int i=0; i<15; i++){
	    pushBuffer(&cb, &i);
	}

	for(int i=0; i<15; i++){
	    popBuffer(&cb);
	}
	
}
