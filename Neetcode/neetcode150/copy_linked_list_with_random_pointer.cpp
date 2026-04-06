/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToNew;
        Node* curr = head;
        while(curr!=nullptr) {
            Node* copy = new Node(curr->val);
            oldToNew[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        while(curr!=nullptr) {
            Node* copy = n
            oldToNew[curr->next] =  
        }
    }
};