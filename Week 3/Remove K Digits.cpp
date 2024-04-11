/* 
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.

*/



class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        for(int i = 0; i < num.size(); i++){  //dips
            while(k > 0 && !stk.empty() && num[i] < stk.top()){
                k--;     //when a dip is found
                stk.pop();
            }
            if(!stk.empty() || num[i] != '0'){   //push
                stk.push(num[i]);
            }
        }
        while(k > 0 && !stk.empty()){   //peaks
            k--;     //for complete steep increasing slope 
            stk.pop(); 
        }
        if(stk.empty())
            return "0";
        string res = "";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
