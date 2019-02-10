# Palindrome Number
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

## Solution
There are two methods to tackle this problem:
- `Convert to string:` convert it to a string and then check it by [Expand Around Center](https://github.com/gzrjzcx/Leetcode/tree/dev/LongestPalindromicSubstring).
- `Split to a half:` It is a brilliant trick that the integer can be split from the middle to a half, and then check whether these two parts are equal or not. Here the feature of **`pop last digit`** from an integer is also taken advantage by this method. Specifically, each time we can get the last digit from the original integer `x`, therefore, it is very convenient to reverse integer, thereby, it is convenient to check if both parts are equal or not as well.

### Split to a half
With the intent of splitting the integer to a half, firstly we need to revert the integer:
- `Revert integer:` [Revert integer](https://github.com/gzrjzcx/Leetcode/tree/dev/reverse_int)
- `The length of the integer:` there are also two cases of the length of the integer:
	- `odd:` in the situation of the length of the integer is odd(e.g., `121`), it is very tricky that we can check if the original integer `x` is greater than the reverted integer `reverted_num`, to guarantee that finally the `reverted_num` is more than one digit than the original integer `x`.  
	**Please note here the original value is decreased with each iteration by `x /= 10`**.  
	Therefore, we can determine whether this integer is a palindrome by:
	```c
	x == reverted_num/10
	```
	- `even:` this case is ordinary without any trap, we can determine whether this integer is a palindrome by:
	```c
	x == reverted_num
	```
  
The process can be diagrammed by the figure !(image)[/palindrome_int/res/palindrome_int.png]:
  
It is clear that in the odd situation, the original `x` is split into `x=1` and `reverted_num = 12`, and finally compare: `x == reverted_num/10`.