#include <stdio.h>
#include <stdlib.h>

#include "resource.h"

int reverse(int x) {
    int pop,result=0;
    
    while(x != 0)
    {
        pop = x%10;
        x /= 10;
        if(result > INT_MAX/10 || (result == INT_MAX/10) && pop > 7) return 0;
        if(result < INT_MIN/10 || (result == INT_MIN/10) && pop < -8) return 0;
        result = result*10 + pop;
    }
    
    return result;
}

int main(int argc, char* argv[]){
	int rev = reverse(1234567);
	printf("%d\n", rev);
}
