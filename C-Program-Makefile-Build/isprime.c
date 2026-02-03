//Prime Number Function 
#include <math.h>
#include <stdio.h>
int isprime(int x){
	int i;
	for (i = 2; i <= sqrt(x); i++) //  This condtion (i * i <= x) is same as the (i <= sqrt(x))
	{
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}