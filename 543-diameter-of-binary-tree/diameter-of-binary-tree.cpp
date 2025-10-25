class Solution {
public:
    int max_diameter=0;
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+ max(levels(root->left) , levels(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int diameter = levels(root->left) + levels(root->right);
        max_diameter = max(max_diameter , diameter);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return max_diameter;
    }
};