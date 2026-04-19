class Deque {
    class Node {
        int value;
        Node* next;
        Node* prev;
        friend class Deque;
        Node(int val, Node* next_node=nullptr, Node* prev_node=nullptr) :
        value(val), next(next_node), prev(prev_node) {}
    };

    Node* head;
    Node* tail;

public:
    explicit Deque() : head(new Node(0)), tail(new Node(0)) {
        head->next = tail;
        tail->prev = head;
    }

    bool isEmpty() {
        return (head->next == tail) && (tail->prev == head);
    }

    void append(int value) {
        Node* node { new Node(value, tail, tail->prev) };
        tail->prev->next = node;
        tail->prev = node;
    }

    void appendleft(int value) {
        Node* node { new Node(value, head->next, head) };
        head->next->prev = node;
        head->next = node;
    }

    int pop() {
        if (isEmpty()) return -1;
        int value  { tail->prev->value };
        Node* last { tail->prev };
        last->prev->next = tail;
        tail->prev = last->prev;
        delete last;
        return value;
    }

    int popleft() {
        if (isEmpty()) return -1;
        Node* first { head->next };
        head->next = first->next;
        first->next->prev = head;
        int value = first->value;
        delete first;
        return value;
    }
};
