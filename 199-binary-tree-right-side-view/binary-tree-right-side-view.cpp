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
    int level_cal(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(level_cal(root->left),level_cal(root->right));
    }
    void helper(TreeNode* root , int curr , int level , vector<int>& ans){
        if(root==NULL) return;
        if(curr == level){
            ans[curr-1] = root->val;
            return;
        }
        helper(root->left , curr+1 , level ,ans);
        helper(root->right , curr+1 , level , ans);
    }
    void level_order(TreeNode* root , vector<int>& ans){
        int n_levels = level_cal(root);
        for(int i = 1 ; i <= n_levels ; i++){
            helper(root , 1 , i , ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        int levels = level_cal(root); 
        vector<int>ans(levels,0);
        level_order(root , ans);
        return ans;
    }
};