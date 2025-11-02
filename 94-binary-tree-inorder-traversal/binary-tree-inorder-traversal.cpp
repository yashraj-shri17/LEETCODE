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
    vector<int> inorderTraversal(TreeNode* root) {
        // MORRIS TRAVERSAL 
        vector<int>ans ;
        TreeNode* curr = root;
        while(curr){
            if(curr->left!=NULL){
                // find predecessor
                TreeNode* pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr) pred = pred->right;
                if(pred->right==NULL){ // link
                    pred->right = curr;
                    curr =  curr->left;
                }
                if(pred->right == curr){ // unlink
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else{ // visit and move forward
                ans.push_back(curr->val);
                curr = curr->right; 
            }
        }
        return ans;
    }
};