#include <stdio.h>
#include <stdlib.h>

#define min_h(a,b) ((a>b)?b:a)
#define max_w(a,b) ((a<b)?b:a)

/* force methhod */
int maxArea_force(int* height, int heightSize) {
    int max = 0;
    for(int l=heightSize; l>0; l--)
    {
        int i,j;
        j = l-1;
        for(; j<heightSize; j++)
        {   
            i=j-l+1;
            if(max < min_h(height[i], height[j]) * (l-1))
                max = min_h(height[i], height[j]) * (l-1);          
        }
    }
    return max;
}

// O(N) method
int maxArea(int* height, int heightSize) {
    int max = 0;
    int i = 0;
    int j = heightSize - 1;
    
    while(i<j)
    {
        max = max_w(max, min_h(height[i], height[j]) * (j-i));
        if(height[i] < height[j])
            i++;
        else
            j--;
    }

    return max;
}

int main(int argc, char* argv[]){
	int input[9] = {1,8,6,2,5,4,8,3,7}; 
	printf("max water container = %d\n", maxArea(input,9));
}
