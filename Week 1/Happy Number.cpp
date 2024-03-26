/* 
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1
*/



class Solution {
public:

    int square_function(int num) {
        int sum = 0;
        while(num) {
            int digit = num % 10;
            sum += digit*digit;
            num /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        if(n <= 0 ){
            return false;
        }

        unordered_set<int> cache;     
        while(cache.find(n) == cache.end()){  //checking if there exists any loop while calculating the sum of squares;
            cache.insert(n);
            n = square_function(n);
            if(n == 1){
                return true;
            }
        }
        return false;
    }
};


----------------------------------------------------------------------------------------------------
Example : 

let's walk through the code step by step with an input of 19:

Initialization:

The input number is n = 19.
The isHappy function is called with n = 19.
Checking Initial Condition:

n is greater than 0, so we proceed.
Creating Cache Set:

An unordered set named cache is created to store encountered numbers during the process.
Entering While Loop:

We enter a while loop because cache.find(n) is equal to cache.end() (meaning n is not found in the cache).
First Iteration of While Loop:

Inside the loop:
cache.insert(n) inserts n = 19 into the cache set.
n is updated to the result of applying the square_function on n.
square_function(19) calculates the sum of squares of digits of 19: 
1^2 + 9^2 =1+81=82

 =1+81=82.
So, n becomes 82.
n is not equal to 1, so the loop continues.
Second Iteration of While Loop:

Inside the loop:
cache.insert(n) inserts n = 82 into the cache set.
n is updated to the result of applying the square_function on n.
square_function(82) calculates the sum of squares of digits of 82: 
8^2+2^2=64+4=68

 =64+4=68.
So, n becomes 68.
n is not equal to 1, so the loop continues.
Third Iteration of While Loop:

Inside the loop:
cache.insert(n) inserts n = 68 into the cache set.
n is updated to the result of applying the square_function on n.
square_function(68) calculates the sum of squares of digits of 68: 
6^2+8^2=36+64=100

 =36+64=100.
So, n becomes 100.
n is not equal to 1, so the loop continues.
Fourth Iteration of While Loop:

Inside the loop:
cache.insert(n) inserts n = 100 into the cache set.
n is updated to the result of applying the square_function on n.
square_function(100) calculates the sum of squares of digits of 100: 
1^2+0^2+0^2=1+0+0=1

 =1+0+0=1.
So, n becomes 1.
n is equal to 1, so the loop exits.
Return Value:

Since n became 1 during the process, the function returns true, indicating that 19 is a happy number.


  -------------------------------------------------------------------------------------------------------------


  If the input is 2, let's walk through the code step by step:

Initialization:

The input number is n = 2.
The isHappy function is called with n = 2.
Checking Initial Condition:

n is greater than 0, so we proceed.
Creating Cache Set:

An unordered set named cache is created to store encountered numbers during the process.
Entering While Loop:

We enter a while loop because cache.find(n) is equal to cache.end() (meaning n is not found in the cache).
First Iteration of While Loop:

Inside the loop:
cache.insert(n) inserts n = 2 into the cache set.
n is updated to the result of applying the square_function on n.
square_function(2) calculates the sum of squares of digits of 2: 
2^2=4
 =4.
So, n becomes 4.
n is not equal to 1, so the loop continues.
Second Iteration of While Loop:

Inside the loop:
cache.insert(n) inserts n = 4 into the cache set.
n is updated to the result of applying the square_function on n.
square_function(4) calculates the sum of squares of digits of 4: 
4^2=16
 =16.
So, n becomes 16.
n is not equal to 1, so the loop continues.
Third Iteration of While Loop:

Inside the loop:
cache.insert(n) inserts n = 16 into the cache set.
n is updated to the result of applying the square_function on n.
square_function(16) calculates the sum of squares of digits of 16: 
1^2+6^2=1+36=37
  
 =1+36=37.
So, n becomes 37.
n is not equal to 1, so the loop continues.
Fourth Iteration of While Loop:

Inside the loop:
cache.insert(n) inserts n = 37 into the cache set.
n is updated to the result of applying the square_function on n.
square_function(37) calculates the sum of squares of digits of 37: 
3^2+7^2=9+49=58
 =9+49=58.
So, n becomes 58.
n is not equal to 1, so the loop continues.
Fifth Iteration of While Loop:

Inside the loop:
cache.insert(n) inserts n = 58 into the cache set.
n is updated to the result of applying the square_function on n.
square_function(58) calculates the sum of squares of digits of 58: 
5^2+8^2=25+64=89
 =25+64=89.
So, n becomes 89.
n is not equal to 1, so the loop continues.
Sixth Iteration of While Loop:

Inside the loop:
cache.insert(n) inserts n = 89 into the cache set.
n is updated to the result of applying the square_function on n.
square_function(89) calculates the sum of squares of digits of 89: 
8^2+9^2=64+81=145

 =64+81=145.
So, n becomes 145.
n is not equal to 1, so the loop continues.
Seventh Iteration of While Loop:
Inside the loop:
cache.insert(n) inserts n = 145 into the cache set.
n is updated to the result of applying the square_function on n.
square_function(145) calculates the sum of squares of digits of 145: 
1^2+4^2+5^2=1+16+25=42

 =1+16+25=42.
So, n becomes 42.
n is not equal to 1, so the loop continues.
Eighth Iteration of While Loop:
Inside the loop:
cache.insert(n) inserts n = 42 into the cache set.
n is updated to the result of applying the square_function on n.
square_function(42) calculates the sum of squares of digits of 42: 
4^2+2^2=16+4=20

 =16+4=20.
So, n becomes 20.
n is not equal to 1, so the loop continues.
Ninth Iteration of While Loop:
Inside the loop:
cache.insert(n) inserts n = 20 into the cache set.
n is updated to the result of applying the square_function on n.
square_function(20) calculates the sum of squares of digits of 20: 
2^2+0^2=4+0=4
  =4+0=4.
So, n becomes 4.
n is already present in the cache set, so the loop exits.
