# CountLCS
Distinct Longest Common Subsequence of given string

## Build Instructions

- Compile the program on Linux using the command: 

      `g++ Main.cc -o MAIN`

- Run using: 

      `./MAIN `

## Program
- Given an integer input n in the range [3:20], the program accepts integer input x and y in the range [0:2^n - 1] 

- `Binstring` converts the decimal integers x and y to binary strings of length n each. 
- `CountLCS` finds the length of the Longest Common Subsequence
- `GetLCS` prints all the LCS's found

## Sample Input and Output

Enter the value of n in range [3:20] 8\
Enter value of x in range [0:255]: 235\
Enter value of y in range [0:255]: 217\
STRINGLEN: 8\
X (235) = 11101011\
Y (217) = 11011001\
Length of LCS: 6\
No. of LCS: 4\
LCS 1: 110101\
LCS 2: 110111\
LCS 3: 111001\
LCS 4: 111101

## Algorithm 
- We first use Bottom-up dynamic programming to find the length of the Longest Common Substring. Let’s say we have two strings, of length m and n, then, we memoize the results of the subproblems of the recursive solution.

- The value memo[m][n] contains length of LCS. 

- We then traceback the memoized array to reconstruct the Longest Common Subsequences.

- While backtracking, we build a bc[m][n] 2D array of objects of the Backtrack class type to cache/memoize the LCS of suffixes of the two strings stored as a set of strings to avoid duplicates in each bc[i][j] value computed. If for each call of GetLCS(i,j,x,y), if it has not been previously computed, then compute the value and store it in bc[i][j] for future use, otherwise get the value from bc[i][j]

## Analysis

- The worst case time complexity of `Binstring` is O(n)
- The worst case time complexity of `CountLCS` is O(n*n)
- The worst case time complexity of the traceback function `GetLCS` is O(p*(n+n)) where p is the number of LCS's found
- Therefore, the total worst case asymptotic time complexity of the algorithm is O(n^2 + 2np + n)