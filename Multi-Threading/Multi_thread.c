// Comile with:
// gcc -pthread -o threadtesttool threadtesttool.c
//

//
// Usage:
// threadtesttool [[num_threads] num_primes_to_find]
//
// OR
//
// nothreadtesttool [[num_threads] num_primes_to_find]
//

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_NUM_THREADS 50
#define DEFAULT_NUM_THREADS 10
#define DEFAULT_PRIMES_TO_FIND 10000000

pthread_t tid[MAX_NUM_THREADS];
int * ptr[MAX_NUM_THREADS];
int gPrimesToFind = DEFAULT_PRIMES_TO_FIND;
int gNumThreads = DEFAULT_NUM_THREADS;
int gNoThreads = 0;

int is_prime(unsigned int n) {
    /*unsigned int p;
    if (!(n & 1) || n < 2) return n == 2;

    for (p = 3; p <= n / p; p += 2)
        if (!(n % p)) return 0;
    return 1;*/

    unsigned int i;
    for (i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

void * doSomeThing(void * arg) {
    int count = 0;
    int i = 0;
    while (i < gPrimesToFind) {
        if (is_prime(i) != 0) {
            count++;
        }
        i = i + 1;
    }

    if(!gNoThreads)
    	pthread_exit( & count);
}

int main(int argc, char * argv[]) {

    if(strstr(argv[0], "nothreadInc")!=NULL) {
	   gNoThreads = 1;
    }

    if (argc == 2) {
        gPrimesToFind = (int) strtol(argv[1], NULL, 10);
    }

    if (argc == 3) {
        gNumThreads = (int) strtol(argv[1], NULL, 10);
        gPrimesToFind = (int) strtol(argv[2], NULL, 10);

        if (gNumThreads > MAX_NUM_THREADS) {
            printf("Too many threads\n");
            exit(-1);
        }
    }

    printf("Threading test tool\n");
    
    if(!gNoThreads) {
	    printf("Threads: %d. Primes to find: %d\n", gNumThreads, gPrimesToFind);
    } 

    else {
	    printf("Iterations: %d. Primes to find: %d\n", gNumThreads, gPrimesToFind);
    }

    int i = 0;
    int err;

    if(gNoThreads) {
    	while(i < gNumThreads) {
    		doSomeThing(NULL);
    		i++;
    	 }
    } 

    else {
    	while (i < gNumThreads) {
        	err = pthread_create( & (tid[i]), NULL, & doSomeThing, NULL);
        	if (err != 0)
            		printf("\nCan't create thread :[%s]", strerror(err));
        	i++;
    	   }

    	i = 0;
    	while (i < gNumThreads) {
            	pthread_join(tid[i], (void ** ) & (ptr[i]));
            	i++;
    	    }
    }
    return 0;
}