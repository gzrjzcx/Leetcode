#include <stdio.h>
#include <stdlib.h>
#include "resource.h"

char* longestPalindrome(char* s) {
    if(!s[0])
        return s;
    int length = strlen(s);
    int max_length = 1;
    int max_i = 0;
    int k = 0;
    
    while(k<length)
    {
        int i=k; 
        int j=k;
        while(j<length-1 && s[j] == s[j+1]) j++;
        k = j+1;
        while(j<length-1 && i>0 && s[i-1] == s[j+1])
        {
            j++;
            i--;
        }
        if(j-i+1 >= max_length)
        {
            max_length = j-i+1;
            max_i = i;
        }
    }
    
    char* p = (char *)malloc((max_length+1)*sizeof(char));
    memcpy(p, &s[max_i], max_length);
    p[max_length] = '\0';
    return p;
}

int main(int argc, char* argv[]){
	char* s = "babad";
	char* p;
	p = longestPalindrome(s);

	for(int i=0; p[i]; i++)
		printf("%c",p[i]);
}