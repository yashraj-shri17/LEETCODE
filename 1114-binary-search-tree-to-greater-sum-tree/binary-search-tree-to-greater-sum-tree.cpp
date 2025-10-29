class Solution {
public:
    void helper(TreeNode* root , int& sum){
        if(root==NULL) return;
        helper(root->right , sum);
        // kaam karoge
        root->val =  root->val + sum;
        sum = root->val;
        //
        helper(root->left , sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        helper(root , sum);
        return root;
    }
};