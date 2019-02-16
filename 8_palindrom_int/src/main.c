#include <stdio.h>
#include <stdlib.h>

#include "resource.h"

bool isPalindrome(int x);
bool isPalindrome(int x) {
    if(x < 0 || (x % 10 == 0 && x > 9))
        return false;
    else
    {
        int reverted_num = 0;
        while(x > reverted_num)
        {
            reverted_num = reverted_num*10 + x%10;
            x /= 10;
        }
        return x == reverted_num || x == reverted_num/10;
    }
}

int main(int argc, char* argv[]){
	printf("%d\n", isPalindrome(1221));
}
