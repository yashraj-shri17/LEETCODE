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
    void helper(TreeNode* root ,long long tsum , int& cnt){
        if(root==NULL) return;
        if(tsum==(long long)root->val){
            cnt++; 
        }
        helper(root->left,tsum-(long long)root->val,cnt);
        helper(root->right,tsum-(long long)root->val,cnt);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int cnt = 0;
        helper(root , (long long)targetSum , cnt);
        cnt = cnt + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
        return cnt;
    }
};