#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        TreeNode* current = root;
        
        while (current != nullptr || !nodeStack.empty()) {
            // Traverse to the leftmost node of the current subtree
            while (current != nullptr) {
                nodeStack.push(current);
                current = current->left;
            }
            
            // Process the leftmost node
            current = nodeStack.top();
            nodeStack.pop();
            result.push_back(current->val);
            
            // Move to the right subtree
            current = current->right;
        }
        
        return result;
    }
};
