class Solution {
public:
    void insert(TreeNode* root , int val){
        if(root==NULL) return ;
        if(root->val > val){
            // go left
            if(root->left==NULL){
                root->left = new TreeNode(val);
            }
            insert(root->left , val);
        }
        if(root->val < val){
            // go right
            if(root->right==NULL){
                root->right = new TreeNode(val);
            }
            insert(root->right , val);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = new TreeNode(pre[0]);
        for(int i=1 ; i < pre.size() ; i++){
            insert(root , pre[i]);
        }
        return root;
    }
};