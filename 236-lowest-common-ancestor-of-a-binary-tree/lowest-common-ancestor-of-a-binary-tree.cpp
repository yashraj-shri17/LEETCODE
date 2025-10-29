/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool exist(TreeNode* root , TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;
        return exist(root->left , target) || exist(root->right , target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return NULL;
        if (exist(root->left, p) && exist(root->left, q))
            return lowestCommonAncestor(root->left, p, q);
        else if (exist(root->right, p) && exist(root->right, q))
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;

    }
};