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