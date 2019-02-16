# Container With Most Water
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

**Note**: Does not slant the container and n is at least 2.

## Solution
The core idea here is that the greater length of the container is intended as the most competitive candidates of the most water. Therefore, we must check each possible combination from outer container to inner possible container. There are two solutions here:
### Force Method --- iterate the bottom length
The natural idea is that iterating all possible length(from large to small) of the input at the outer loop firstly, and then check each possible height at the inner loop.
```c
    for(int l=heightSize; l>0; l--)
    {
        int i,j;
        j = l-1;
        for(; j<heightSize; j++)
        {   
        	// each time j = index of rightmost column(according to the length l)
            i=j-l+1;
            if(max < min_h(height[i], height[j]) * (l-1))
                max = min_h(height[i], height[j]) * (l-1);          
        }
    }
```
Supposing the `[1,8,6,2,5,4,8,3,7]` as the input example, then as you can see:
-  In the first iteration(i.e., the longest length(9) situation), the leftmost column(`i=0`) and the rightmost(`j=7`) column are checked, because now the length `l=heightsize`.
- In the second iteration(i.e., length `l=8`), the columns `i=0, j=7` and `i=1, j=8` are checked.
Finally, we can get the maximum value of the capacity of the container.

### Improvement -- iterate the columns
In fact, there are some redundant computations because the essence of the most water is the most height of the columns and the most length of the bottom. Firstly, because it must be a container, therefore, in terms of he index, must have `i<j`, Then, with the intent of finding the most water, we can use the strategy: 
```c
    while(i<j)
    {
        max = max_w(max, min_h(height[i], height[j]) * (j-i));
        if(height[i] < height[j])
            i++;
        else
            j--;
    }
```
It means that each time only the shorter column will be substituted by the next column, because it is the determinant of the capacity of the container. Thus the other column will be used for the next container, because it can be intended as the highest column in this stage, and the most water container must be composed by this column. 