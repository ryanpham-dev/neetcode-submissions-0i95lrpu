
class LinkedList {
    struct Node {
        int value;
        Node* next;
        Node() : next{} {}
        explicit Node(int val, Node* next_node=nullptr) : value { val }, next{ next_node } {};
};

    Node* head;
    Node* tail;
public:
    LinkedList() : head (new Node(-1)) {
        tail = head;
    }

    int get(int index) {
        Node* current = head->next;
        int i = 0;
        while (current != nullptr) {
            if (i == index) {
                return current->value;
            }
            i++;
            current = current->next;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* node = new Node(val, head->next);
        head->next = node;
        if (node->next == nullptr) {
            tail = node;
        }
    }
    
    void insertTail(int val) {
        tail->next = new Node(val);
        tail = tail->next;
    }

    bool remove(int index) {
        Node* current = head;
        int i = 0;
        while (i < index && current != nullptr) {
            i++;
            current = current->next;
        }
        if (current != nullptr && current->next != nullptr) {
            if (current->next == tail) {
                tail = current;
            }
            Node* to_delete = current->next;
            current->next = current->next->next;
            delete to_delete;
            return true;
        }
        return false;
        
    }

    vector<int> getValues() {
        vector<int> output;
        Node* current = head->next;
        while(current) {
            output.emplace_back(current->value);
            current = current->next;
        }
        return output;
    }
};
