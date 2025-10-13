#include <stdio.h>
#include <stdlib.h>
#include "number_utils.h"

int main()
{
	int a;
	printf("\nEnter your fav number: ");
	scanf("%d",&a);
	if(isprime(a)){
		printf("\nIt is a prime Number\n");                 	// Not Prime NUmber
	}
	else{
		printf("\nIt is not a Prime Number\n");                	// Prime Number
	}

	isoddeven(a);
	return 0;
}