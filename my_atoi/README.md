# myAtoi
Implement `atoi` which converts a string to an integer.

## Solution
The main idea is that to find **the first non-whitespace** in the original string. Once we have found it, then there are there possible situations of the first non-whitespace character:
- `Digit:` it is the start of the real conversation which from `char` to `int`. Please note that each time we only can get one digit from the string, therefore we also need to **interpret it as the practical numerical value**. This is similar to the `reverse int value`, using `pop` to get the last digit of the original string:
```c
int pop = (str[i]-'0');
if(num > INT_MAX/10 || (num == INT_MAX/10) && pop > 7)
    return INT_MAX;
if(num < INT_MIN/10 || (num == INT_MIN/10) && pop > 8)
    return INT_MIN;
if(negative_flag)
    num = num*10 - pop;
else
    num = num*10 + pop;
```
The difference here is that the negative situation should be taken into account. Therefore, when the negative overflow problem is checked, we set it is `pop > 8`, because the character we get each time from string is an `unsigned` digit(e.g., `"123", s[0]='1', '1' is an unsigned character`). The detailed explanation can be checked [here](https://github.com/gzrjzcx/Leetcode/tree/dev/reverse_int).
- `'+' or '-':` The `+` or `-` decide the practical numerical value of the converted integer. Therefore, a flag is intended to check the integer is positive or negative:
```c
if(start_flag && str[i] == '-' && (str[i+1] >= '0' && str[i+1] <= '9'))
```
Please note here we also need to check one special possible situation: `+-123`.
In this case, it is an invalid integer because the first non-whitespace character is the `+` but the following is the `-` as well, instead of the `integer` value. As a consequence, the `(str[i+1] >= '0' && str[i+1] <= '9')` is used to check if the following character is a digit or not.  
Moreover, the `start_flag` is intended as the flag to indicate if the conversation is start or not, because once the conversation is start(i.e., the first non-whitespace character is valid), then even the following character is **whitespace**, it is also an invalid case, instead of skipping the whitespace. For instance, `12 34`, the result is `12`.
- `Other character:` once the first non-whitespace character is not a `integer` value, it can be confirmed that this is an invalid case.
  
Additionally, in terms one of the possible situation: `-123+1`, the result will be `-123` because by the explanation of the original `atoi` function, once the first **non-whitespace** character is not the numerical digits, the conversation is finished.


