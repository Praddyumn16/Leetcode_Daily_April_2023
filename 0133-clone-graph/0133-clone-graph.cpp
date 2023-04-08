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
    void dfs(Node* curr , unordered_map<Node* , Node*>& mp , unordered_map<Node* , int>& visited) {
        
        visited[curr] = 1;
        
        if(!mp.count(curr))
            mp[curr] = new Node(curr->val);
        
        for(auto a : curr->neighbors) {
            if(!visited[a])
                dfs(a , mp , visited);
        }
    }
    
    Node* cloneGraph(Node* node) {
        
        if(!node)
            return NULL;
     
        unordered_map<Node* , Node*> mp; 
        unordered_map<Node* , int> visited;
        dfs(node , mp , visited);
        
        for(auto a : mp) {
            for(auto neighbor : a.first->neighbors)
                a.second->neighbors.push_back(mp[neighbor]);
        }
        
        return mp[node];
        
    }
};