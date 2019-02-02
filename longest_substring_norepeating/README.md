# Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.
## Solution
The main idea is that splitting the original string to different substrings, and then check if this substring includes the repeating characters.
## Algorithm
Using outer loop(i.e., `loop i`) to iterate the original string, to visit all of the characters in the whole string. Using the inner loop(i.e., `loop j`) to visit all of the characters in the **substring**. Once there are two same characters in a substring, we set **`j_start`** to the `i`, it means that we have started a new iteration from a **new substring**. And each time the substring is updated, we will check if the `max_norepeating_length` is greater than the `current_norepeating_length` to acquire the maximum length of the substring without repeating characters.
The core idea can be diagrammed as the below graph. For example:  
![longest_substring_norepeating](/longest_substring_norepeating/res/longestNorepeatSubstring.png)
  
- In the start point, assuming that the initial value of `i=1`, and the initial value of `j_start=0`. It means that we suppose the first substring is `ab`. Using the `j` to iterate the substring `ab` to check that if there is a character is same as the `s[i]`. Obviously, `s[j] != s[i]`, here `j=0` and `i=1`. Therefore, the substring go further to the `i=2`.
- In the `i=2` situation, the substring now is `abc`. But please note that here the `j_start` is still `0`. Then, we also use the `j` to iterate the whole substring. And the there is still no repeating characters in this substring.
- When `i=3`, the substring becomes to `abca`, and also the `j_start=0`, which means that the substring `abca` will be visited by `j` from `j=j_start`. However, in this substring, there are the repeating characters. Then here the `j_start` will be set to the current `j`.
- As shown at `i=4`, the new substring is `ab`, which is split from `j=3` and `i=4`. Then, repeating the process described above, to acquire the longest length without repeating characters.