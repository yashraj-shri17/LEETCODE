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
    void helper(TreeNode* root , unordered_map<int,int>& mp){
        if(root==NULL) return;
        helper(root->left , mp);
        mp[root->val]++;
        helper(root->right , mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        helper(root , mp);
        int max_ele = INT_MIN;
        for(auto x : mp){
            max_ele = max(max_ele , x.second);
        }
        vector<int>ans;
        for(auto x : mp){
            if(x.second==max_ele)ans.push_back(x.first);
        }
        return ans;  
    }
};