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
        std::unordered_map<Node*, Node*> connectedMap{};
        Node* current = head;

        while (current) {
            connectedMap[current] = new Node(current->val);
            current = current->next;
        }
        current = head;

        while (current) {
            connectedMap[current]->next = connectedMap[current->next];
            connectedMap[current]->random = connectedMap[current->random];
            current = current->next;
        }
        return connectedMap[head];
    }
    
};
