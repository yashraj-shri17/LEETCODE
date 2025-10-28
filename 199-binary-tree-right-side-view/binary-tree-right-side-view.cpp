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
 // Levels FUCNTION
class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void helper(TreeNode* root , int curr , int level,vector<int>& ans){
        if(root==NULL) return;
        if(curr == level){
            ans[curr] = root->val;
            return;
        }
        helper(root->left , curr+1 , level,ans);
        helper(root->right , curr+1 , level,ans);
    }
    void level_order(TreeNode* root, vector<int>& ans){
        int n_levels = ans.size();
        for(int i = 0 ; i < n_levels ; i++){
            helper(root , 0 , i,ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans(levels(root),0);
        level_order(root , ans);
        return ans;
    }
};