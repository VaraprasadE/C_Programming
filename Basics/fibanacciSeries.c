#include<stdio.h>

int main(){
    int n = 10; // You can change this or scan it from user
    int a = 0, b = 1, temp;
    
    printf("%d, %d", a, b); // Print first 2 terms

    // Start loop from 2 because we already printed 2 terms
    for(int i = 2; i < n; i++){ 
        temp = a + b;
        a = b;
        b = temp;
        printf(", %d", temp); // Added a comma for cleaner formatting
    }
    return 0;
}