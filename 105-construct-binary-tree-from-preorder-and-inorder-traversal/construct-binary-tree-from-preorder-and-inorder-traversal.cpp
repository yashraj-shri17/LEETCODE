class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preLo, int preHi, int inLo, int inHi) {
        if (preLo > preHi || inLo > inHi) return NULL;

        TreeNode* root = new TreeNode(preorder[preLo]);

        int idx = inLo;
        while (idx <= inHi && inorder[idx] != root->val) idx++;

        int leftSize = idx - inLo;

        root->left = helper(preorder, inorder, preLo + 1, preLo + leftSize, inLo, idx - 1);
        root->right = helper(preorder, inorder, preLo + leftSize + 1, preHi, idx + 1, inHi);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preLo = 0, preHi = preorder.size() - 1;
        int inLo = 0, inHi = inorder.size() - 1;
        return helper(preorder, inorder, preLo, preHi, inLo, inHi);
    }
};
