#include <stdio.h>
#include <stdlib.h>
#include "resource.h"

char* convert(char* s, int numRows);

char* convert(char* s, int numRows) {
    int length = strlen(s);
    if(length <= numRows || length < 2 || numRows < 2)
        return s;
    int iter_length = 2*numRows - 2;
    int i=0, j=0, cur=0;
    int col=0;
    
    char* p = (char *)malloc((length+1)*sizeof(char));

    while(col < numRows)
    {
        i = col;
        if(col == 0 || col == numRows-1)
        {
            while(i < length)
            {
                p[cur] = s[i];
                cur++;
                i += iter_length;
            }            
        }
        else
        {
            while(i < length)
            {
                p[cur] = s[i];
                cur++;
                j = iter_length+i-2*col;
                if(j < length)
                {
                    p[cur] = s[j];                    
                    cur++;
                }
                i += iter_length;
            }
        }
        
        col++;  
    }
    p[length] = '\0';
    return p;
}

int main(int argc, char* argv[]){
	char* p;
	char* s = "PAYPALISHIRING";
	
	p = convert(s,3);
	for(int i=0; p[i]; i++)
	{
		printf("%c", p[i]);
	}
}
