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
        std::unordered_map<int, Node*> map{};
        Node* other = head;
        Node dummy(0);
        Node* current = &dummy;
        while (other != nullptr) {
            current->next = new Node(other->val);
            map[other->val] = current->next;
            current = current->next;
            other = other->next;
        }
        other = head;
        current = dummy.next;
        while (other != nullptr) {
            if (Node* randomNode = other->random; randomNode != nullptr) {
                current->random = map[randomNode->val];
            }
            current = current->next;
            other = other->next;
        }
        return dummy.next;
    }
};
