/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*>node_register;
    void dfs(Node* clone , Node* actual){
        for(auto neighbours : actual->neighbors){
            if(node_register[neighbours->val]==NULL){ // not visited
                Node* newNode = new Node(neighbours->val);
                node_register[neighbours->val] = newNode;
                clone->neighbors.push_back(newNode);
                dfs(newNode , neighbours);
            }
            else{
                clone->neighbors.push_back(node_register[neighbours->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* clone = new Node(node->val);
        node_register.resize(105,NULL);
        node_register[node->val] =  clone;
        dfs(clone , node);
        return clone;
    }
};