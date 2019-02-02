# zigzag conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like figure:

## Solution
The main idea is that the whole string will be divided into several substrings according two patterns: `vertical` and `diagonal`. Then iterating the whole original strings by the lines. For example, the `numRows=4`, indicating that there will be 4 lines in total, then iterating these 4 rows to add elements to new string in order following each line. Specifically, in terms of the first line(`line=0`), firstly picking up the `P` from whole string, and then picking up `I` character from whole string. The methods about how to pick up characters from whole sting are dependent on the different strategies.   

##### Pattern

The solution can be diagrammed as the figure below. Obviously, there are two patterns to re-arrange the string:  
  
![image](/res/zigzag.png)
  
- `Vertical:` It means that the elements are structured vertically. It can be noted that the elements are arranged in order to the rows.
- `Diagonal:` It means that the elements are structured diagonally. Please note that here the elements are arranged from bottom to top. And we consider that the first character and last character in each row as belong to the `vertical` pattern. For example, the first character `P` and the last character `P` in the `row=0` are belong to the `row=1`. In other words, there is only `A` in `row=1`, only `L` in `row=2`.  

##### Strategy

Then we need to pick up the suitable character from the original string `s` to fill the new string `p`, and there are two strategies to choose:  
- `strategy 1:` Investigating the re-constructed strings, we can see that the first line(`line=1`) can be picked from **the first character** in the `vertical area 1`, `vertical area 2` and `vertical area 3`. Similarly, the last line can be picked from **the last character** in the `vertical area 1`and `vertical area 2`.  
- `strategy 2:` In terms of the inner lines(i.e., `line=1 and line=2`), we need to pick up the characters from `vertical area` and `diagonal area` alternately. Because the elements are arranged from bottom to top in `diagonal area`, the elements will be picked up from `diagonal area` is in reverse order. For example:  
	- In the `line=1`, the first character `A` is from the **first** character in `vertical 1`.
	- In the `line=1`, the second character `L` is from the **last** character`diagonal 1`. 
  
In the same way, the third character `S` and the forth character `I` is are come from the first and last character in `vertical 2` and `diagonal 2` respectively. Please note that in the `vertical 3`, there are some characters also need to be picked up according to the strategy.  
Then, as for `line=2`, the first character is the next element in the `vertical 1`, the second character is the previous element in the `diagonal 1`.

##### Summarization
- We need to know the **cycle** length(i.e., one `vertical area length` plus one `diagonal area length`), and then we need to pick up the character according to each cycle in order.
- We pick up the characters from original string according to the different strategies, and iterated by the total lines(`numRows=4` means that there will be `4` lines).

## Notes
- When using `while(s[i])` to iterate the string, must pay attention to that if `i>strlen(s)`, this method will be invalid because in this situation `s[i]` will  get a random value. However, it also satisfy the `while(s[i])` condition. 
	- Therefore,   typically, `while(s[i])` only can be used as increasing step is **1**(i.e., `i++`), and must note that if there is `i>length`.

- In most cases `Runtime Error` in C program is that we have accessed unaccessable memory. Specifically, it is a typical case that we when we  iterating the loop(i.e., `while(s[i]`), if in some cases that `i>length` of the `char* s`, then it is the `Runtime error` because we want to access the unallocated memory. String `s` doesn't have the `i` element.



