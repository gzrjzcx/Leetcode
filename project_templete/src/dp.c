#include <stdio.h>
#include <stdlib.h>
#include "resource.h"

char* longestPalindrome(char* s) {
    if(!s[0])
        return s;
    int length = strlen(s);
    int max_length = 1;
    int max_i = 0;
    int max_j = 0;
    
    /* check if the sub_substring of current substring is palindrome */
    int sub_substring[length][length];
    for(int k=0; k<length; k++)
        for(int l=0; l<length; l++)
        {
            if(k==l)
                sub_substring[k][l]=1;
            else
                sub_substring[k][l]=0;
        }
    
    for(int sub_length=2; sub_length <= length; sub_length++)
    {
        for(int i=0; i<length-sub_length+1; i++)
        {
            int j = i+sub_length-1;
            //printf("substring length = %d, (i+1,j-1)--->sub_subsgring[%d][%d]=%d, (i,j)--->sub_subsgring[%d][%d]=%d\n", sub_length, i+1,j-1,sub_substring[i+1][j-1],i,j,sub_substring[i][j]);
            if((sub_length==2 || sub_substring[i+1][j-1] == 1) && s[i] == s[j])
            {
                sub_substring[i][j]=1;
                if(sub_length >= max_length)
                {
                    max_length = sub_length;
                    max_i = i;
                    max_j = j;
                }
            }
        }
    }
    
    char* p = (char *)malloc((max_length+1)*sizeof(char));
    printf("max_i=%d, max_j=%d, max_length=%d\n",max_i,max_j,max_length);
    for(int k=0; k<max_j-max_i+1; k++)
        p[k] = s[k+max_i];
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
