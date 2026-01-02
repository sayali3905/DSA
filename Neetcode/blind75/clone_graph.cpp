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

//DFS
class Solution {
public:
    unordered_map<Node*, Node*> oldToNew;
    Node* cloneGraph(Node* node) {
        if(node==nullptr) {
            return nullptr;
        }
        if(oldToNew.count(node)) {
            return oldToNew[node];
        }
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;
        for(Node* nei: node->neighbors) {
            copy->neighbors.push_back(cloneGraph(nei));
        }
        return copy;
    }
};

//BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==0) {
            return nullptr;
        }
        unordered_map<Node*, Node*>clone;
        queue<Node*> q;
        clone[node] = new Node(node->val);
        q.push(node);
        while(q.empty()==0) {
            Node* current = q.front();
            q.pop();
            for(Node* nei : current->neighbors) {
                if(clone.find(nei)==clone.end()) {
                    clone[nei] = new Node(nei->val);
                    q.push(nei);
                }
                clone[current]->neighbors.push_back(clone[nei]);
            }
        }
        return clone[node];
    }
};