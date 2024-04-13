/* 
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

*/




class Solution {
public:
    int largestArea(vector<int> &dp) {
        stack<int> stk;
        stk.push(-1);
        int area = 0;
        for(int i = 0; i <= dp.size(); i++){
            int val = (i == dp.size())?-1:dp[i];
            while(stk.top() != -1 && dp[stk.top()] >val) {
                int height = dp[stk.top()];
                stk.pop();
                int width = i - stk.top() -1;
                area = max(area, height*width);
            }
            stk.push(i);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        if(n+m ==2) return matrix[0][0] =='1';
        vector<int> dp(m,0);
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0') dp[j] = 0;
                else dp[j]++;

            }
            res = max(res, largestArea(dp));
        }
        return res;
    }
};
