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
    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> visited;
        
        if (node == nullptr) {
            return nullptr;
        }
        
        Node* ret = explore(node, visited);
        return ret;
        // std::cout << ret -> neighbors << std::endl;
        
        
    }
    
    // Huge note: Pass visited by reference, use the address of 
    Node* explore(Node* node, std::unordered_map<Node*, Node*> &visited) {
        
        // deep copy current node
        
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        
        Node * ret = new Node(node -> val);
        visited[node] = ret;
        
        vector<Node*> neighbor_list = node -> neighbors;
        
        // iterate through neighbor list and update
        for (Node* neighbor : neighbor_list) {
           (ret -> neighbors).push_back(explore(neighbor, visited));
        }
        
        
        return ret;
    }
};