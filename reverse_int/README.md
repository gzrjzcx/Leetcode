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
- `result * 10 overflow directly:` it means that the new result(i.e., `result * 10`) > INT_MAX.
- `result * 10 not overflow, but result * 10 + pop overflow:` it means that the new result(i.e., `result * 10`) == INT_MAX, but there is also the unit digit will be pulsed and cause overflow. Because `2^31-1 = 2147483647`, therefore, in this situation the `pop` must less than `7`: `pop <= 7`
It is similar to the negative integer situation.