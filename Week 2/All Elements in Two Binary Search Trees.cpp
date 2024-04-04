/* 
Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

The number of nodes in each tree is in the range [0, 5000].
-105 <= Node.val <= 105

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void inorderTraversal(TreeNode* root, vector<int>& result) {
    if(root == NULL)
        return;

    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);    
    
    }

    vector<int> mergeVectors(vector<int>& v1, vector<int>& v2) {
        vector<int> merged;
        int i = 0, j = 0;
        while(i < v1.size() && j < v2.size())
            if(v1[i] < v2[j])
                merged.push_back(v1[i++]);
            else
                merged.push_back(v2[j++]);
        
        while(i < v1.size())   //for any missing elements of v1
            merged.push_back(v1[i++]);
        while(j < v2.size())   //for any missing elements of v2
            merged.push_back(v2[j++]);
        
        return merged;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result1, result2;
        inorderTraversal(root1, result1);
        inorderTraversal(root2, result2);
        return mergeVectors(result1, result2);
    }
};
