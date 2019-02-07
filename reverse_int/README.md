# Reverse Integer
Given a 32-bit signed integer, reverse digits of an integer.

## Solution
  
![reverse_int](/reverse_int/res/reverse_int.png)
  
The core idea can be diagrammed as in figure above, we will iterate all of the digits in the integer `x`, and pick up the last digit in each iteration to accumulate to get the reversed integer.
  
**Note that at each iteration the result will do `result * 10` operation, which means that the we can get the real value of the each digit in the original integer instead of only digit value.** For example, when we got the last digit `7`, it only means an integer `7` in the original value. However, in the reversed integer, `7` means `7 millions`. Therefore, with the iterations increased, the `7` will multiply the equal times of the original digits. As a consequence, the real value of the reversed integer will be guaranteed.
  
Specifically, each time we can pop the last digit(i.e., `7` in `x=1234567`) by `%` operation:
```c
pop = x % 10 // 7;
```
After getting the last digit, then we can assign this digit to the new integer `result` as the **first** digit in the new integer:
```c
result = result * 10 + pop;
```
Finally, we only need to put off the last digit of integer `x`: 
```c
c /= 10;
```
Here the overflow problem also needed to be taken into accounts. Because the problem is given a 32-bit signed integer, which means that the range of the integer is `[-2^31, 2^31-1]`. Therefore we need to check if the new result is overflow:
```c
if(result > INT_MAX/10 || (result == INT_MAX/10) && pop > 7) return 0;
if(result < INT_MIN/10 || (result == INT_MIN/10) && pop < -8) return 0;
```
There are two situations of the overflow, which can be showed from the above figure:
- `result * 10 overflow directly:` it means that the new result(i.e., `result * 10 > INT_MAX.`)
- `result * 10 not overflow, but result * 10 + pop overflow:` it means that the new result(i.e., `result * 10 == INT_MAX`), but there is also the unit digit will be pulsed and cause overflow. Because `2^31-1 = 2147483647`, therefore, in this situation the `pop` must less than `7`: `pop <= 7`

It is similar to the negative integer situation.

## Approach 2:
There is the other method to check if the result overflow more elegant:
```c
int reverse(int x) {
    long long val = 0;
	do 
	{
		val = val * 10 + x % 10;
		x /= 10;
	} while (x);
	
	return (val > INT_MAX || val < INT_MIN) ? 0 : val;
}
```
Here, `long long int` is a **64-bit** integer, which the range is `[-2^63,2^63]`, therefore here we only need to check if the `val` is greater than `INT_MAX` or not.

## Notes
### Do...While loop
In `C/C++`, the do...while loop in C programming checks its condition at the bottom of the loop. It means that the **`do...while` loop is guaranteed to execute at least once**, this is the difference with other loop like `for`.  
  
Therefore, there is a elegant method to do the nested `if` statements:
```c
if( A==true )                               do
{											{		
    if( B==true )								if(A==false)
    {												break;	
        if( C==true )							if(B==false)	
        {											break;
            if( D==true )     -->    			if(C==false)
            {										break;
                ...								if(D==false)
            }										break;
        }										...
    }										}while(false)
```
Here, because `do...while` loop will be executed at least once, therefore, even the condition is `while(false)`, the code also will be executed once. And then the `break` is used to jump out to the `do...while` loop once one condition is not met.