/* 
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

*/


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_height(n), right_height(n);
        left_height[0] = height[0];
        right_height[n-1] = height[n-1];
        int water = 0;

        for(int i = 1; i < n; i++){
            left_height[i] = max(height[i], left_height[i-1]);  // [1,1,2,2,2,2,3,3,3,3,3]
            right_height[n-1-i] = max(height[n-1-i], right_height[n-i]);   // [3,3,3,3,3,3,3,2,2,2,1]
        }

        for(int i = 1; i < n-1; i++){
            water += min(left_height[i], right_height[i]) - height[i];
        }

        return water;


    }
};
