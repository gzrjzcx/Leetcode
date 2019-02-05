# Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.  
Palindromic Explanation:
```
A palindrome is a word, number, phrase, or other sequence of characters  
which reads the same backward as forward.
```
## Solution
The core idea of this problem is that we can check if a string(e.g., `p[i][j]`) is a palindrome by checking if its substring(`p[i-1][j+1]`) is a palindrome. Therefore, we can define a palindromic string(`p[i][j]`) as following:
```
1. The substring p[i+1][j-1] is the palindrome
2. p[i] == p[j]
```
### Dynamic Programming(DP) Approach
- According to the definition of the palindrome, we can using an array to store the flags of if a substring is palindromic or not. As a consequence, we will initialize an 2-d array to store them, and initializing the `sub_substring[i][j]=1, if i==j`, otherwise `sub_substring[i][j]==0`.
- Then check each substrings of its string by the **length of the substring**. In other words, we will iterate this original string from `substring_length=2` to `substring_length<=length`.
- Then in terms of the substring, we can make the `j=i+sub_length-1`(i.e., the end of this substring). Therefore, we can check that `if(sub_substring[i+1][j-1] == 1) && s[i]==[j]`, we can consider that this substring is the palindrome.  
![dp](/LongestPalindromicSubstring/res/dp.png)  
As you can see:
- `substring length = 2:` in this situation, each substring with `length=2` will be iterated and checked if it is palindromic. Obviously, only `s[i]==s[j]` is met the condition of the palindrome. Here, there is no palindrome in all substrings with length is 2.
- `substring length = 3:` Similarly to the previous step, but the length of the substring increased to 3. Because `s[0] == s[2] && sub_substring[0+1][2-1]==1`, therefore, the substring `bab` is a palindrome. In the meantime, we will set the `sub_substring[0][2]=1` as the guidance for the checking of the longer substring.
- `Repeating previous process until the length of the substring is equal to the original string.`

### Expand Around Center Approach
The main idea of this method illustrated as finding the center of each palindromic substrings, and then expanding from it to acquire the longest palindromic substring. Specifically, there are 2 patterns of center:  
- `Center are 2 characters:` For example, the center of the `cbba` is `bb`.
- `Center is 1 character:` For example, the center of the `bab` is the `a`.
  
Firstly, the algorithm can be diagrammed as the figure:  
![dp](/LongestPalindromicSubstring/res/expand.png) 
  
we assuming that the longest substring is `s[1][length-1]`, and then we will find the center in this substring. 
- `Find double characters center(center = 2):` We will find this pattern firstly. Initially, `i=j=k=0`, and `s[j] != s[j+1]`, therefore `k++`. Then `i=j=k=1`, here `s[j] == s[j+1]`, therefore then `j=6`, and meanwhile `i>0 && j<length-1 && s[i-1] != s[j+1]`, we can get the substring `aaaaaa` is the palindromic substring.
- `Find single character center(center = 1):` When `center = 1`, we can see that when `i=j=k=1`, there is no 2 equal contiguous characters and then in the meanwhile `i>0 && j<length-1 && s[i-1] == s[j+1]`, therefore, we have found a center **`a`**, we will expand it to longer substring by increasing `j` and decreasing `i`. As the result, `i` will not meet the condition `i>0`, thereby, this palindrome only have 3 characters. 

## Notes
### Different results between `Run code` and `Submit`
The results between `Run code` pattern and `Submit` pattern are different, one of the possible reason is that the array is **`not initialized`** in `C/C++` language.

```c
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
```
Please note that `C/C++` is different from `Java`, `C/C++` will not zero heap memory for us. Which means that if we do not **initialize** the array, the value of this array in `C/C++` are random.   
Therefore, if we want to use the `sub_substring` to store the palindromic statis of sub-string, we should initialize it with a certain value.

### Get a substring of a char*
We can use the `memcpy` function to achieve the `substring` function in Java:
```c
char* p = (char *)malloc((max_length+1)*sizeof(char));
/*max_i indicates the start of the index in the original substring
max_length indicates the length of the substring will be copied*/
memcpy(p, &s[max_i], max_length);
p[max_length] = '\0';
```
Using this function should include the `<string.h>`.

References:
- [different between Java and C](https://stackoverflow.com/questions/51494403/different-results-on-leetcode-by-submit-solution-and-run-code)

- [substring in C](https://stackoverflow.com/questions/4214314/get-a-substring-of-a-char)

