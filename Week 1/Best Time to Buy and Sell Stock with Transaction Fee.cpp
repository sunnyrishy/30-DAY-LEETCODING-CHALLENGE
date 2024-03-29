/* 
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104

*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0];    
        int sell = 0;
        for(int price : prices){
            int temp = buy;
            buy = max(buy, sell-price);
            sell = max(sell, temp + price - fee);
        }
        return sell;
    }
    
};





Let's go through the code step by step with the given input:

Input: prices = [1,3,7,5,10,3], fee = 3

Initialize buy to -1 (negative of the first price) and sell to 0:

buy = -1
sell = 0
Iterate through each price in the prices vector:

a. For price = 1:

temp = buy = -1 (previous buy value)
buy = max(-1, 0 - 1) = max(-1, -1) = -1
sell = max(0, -1 + 1 - 3) = max(0, -3) = 0
b. For price = 3:

temp = buy = -1 (previous buy value)
buy = max(-1, 0 - 3) = max(-1, -3) = -1
sell = max(0, -1 + 3 - 3) = max(0, -1) = 0
c. For price = 7:

temp = buy = -1 (previous buy value)
buy = max(-1, 0 - 7) = max(-1, -7) = -1
sell = max(0, -1 + 7 - 3) = max(0, 3) = 3
d. For price = 5:

temp = buy = -1 (previous buy value)
buy = max(-1, 3 - 5) = max(-1, -2) = -1
sell = max(3, -1 + 5 - 3) = max(3, 1) = 3
e. For price = 10:

temp = buy = -1 (previous buy value)
buy = max(-1, 3 - 10) = max(-1, -7) = -1
sell = max(3, -1 + 10 - 3) = max(3, 6) = 6
f. For price = 3:

temp = buy = -1 (previous buy value)
buy = max(-1, 6 - 3) = max(-1, 3) = 3
sell = max(6, -1 + 3 - 3) = max(6, -1) = 6
After iterating through all prices, the maximum profit achievable is stored in sell, which is 6.

So, for the given input prices = [1,3,7,5,10,3] with a transaction fee of 3, the maximum profit achievable is 6.
