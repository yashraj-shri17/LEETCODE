class Solution {
public:
    int height(TreeNode *root, bool &ans)
    {
        if (root == NULL)
        {
            return 0;
        }

        int l = height(root->left,ans);
        int r = height(root->right,ans);

        // find if not balanced
        if(abs(l-r) > 1){
            ans = false;
        }
        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        bool ans = true;
        height(root,ans);
        return ans;
    }
};