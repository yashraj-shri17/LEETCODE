class Solution {
public:
    int calculate_levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(calculate_levels(root->left),calculate_levels(root->right));
    }
    void nth_level(TreeNode* root , int curr , int level , vector<int>& temp){
        if (root == NULL) return ;
        if(curr==level){
            temp.push_back(root->val);
            return ;
        }
        nth_level(root->left ,curr+1 , level , temp);
        nth_level(root->right ,curr+1 , level , temp);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = calculate_levels(root);
        vector<vector<int>>ans;
        for(int i = 1 ; i <= n ; i++){
            vector<int>temp;
            nth_level(root , 1 , i , temp);
            ans.push_back(temp);
        }
        return ans;
    }
};