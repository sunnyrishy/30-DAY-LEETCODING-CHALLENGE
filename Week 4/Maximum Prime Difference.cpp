/* 

You are given an integer array nums.

Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.

 

Example 1:

Input: nums = [4,2,9,5,3]

Output: 3

Explanation: nums[1], nums[3], and nums[4] are prime. So the answer is |4 - 1| = 3.

Example 2:

Input: nums = [4,8,2,8]

Output: 0

Explanation: nums[2] is prime. Because there is just one prime number, the answer is |2 - 2| = 0.

 

Constraints:

1 <= nums.length <= 3 * 105
1 <= nums[i] <= 100
The input is generated such that the number of prime numbers in the nums is at least one.


*/



class Solution {
public:
    bool prime_check(int n){
    if(n <= 1){
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
    }
    
    int maximumPrimeDifference(vector<int>& nums) {
        int index = -1;
        int max_distance = 0;
        for(int i = 0; i < nums.size(); i++){
            if(prime_check(nums[i])){
                if(index != -1){
                    max_distance = max(max_distance, i-index);
                }
                else {
                    index = i;   //for the first occurance
                }
            }
        }
        return index == -1?0:max_distance;
    }
};
