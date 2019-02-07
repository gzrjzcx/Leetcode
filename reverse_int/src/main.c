#include <stdio.h>
#include <stdlib.h>

#include "resource.h"

int reverse(int x) {
	long long result = 0;
	do 
	{
		result = result * 10 + x % 10;
		x /= 10;
	} while (x);
	
	return (result > INT_MAX || result < INT_MIN) ? 0 : result;
}

int main(int argc, char* argv[]){
	int rev = reverse(1234567);
	printf("%d\n", rev);
}
