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
    int cnt ;
    void preorder(TreeNode* root){
        if(root==NULL) return;
        cnt++;
        preorder(root->left);
        preorder(root->right);
    }
    int countNodes(TreeNode* root) {
        cnt = 0;
        preorder(root);
        return cnt;
    }
};