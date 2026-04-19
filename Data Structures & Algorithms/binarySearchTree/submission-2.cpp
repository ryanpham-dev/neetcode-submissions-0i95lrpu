#include <stack>
#include <utility>
#include <memory>
#include <vector>

struct Node {
    std::pair<int, int> element;
    std::unique_ptr<Node> left_;
    std::unique_ptr<Node> right_;
    Node(int key, int val, std::unique_ptr<Node> left = nullptr, std::unique_ptr<Node> right = nullptr) : element(key, val), left_(std::move(left)), right_(std::move(right)) {}
};

class TreeMap {
private:
    std::unique_ptr<Node> root_;
    unsigned int size;

    void insert(std::unique_ptr<Node>& node_ptr, int key, int value) {
        if (node_ptr == nullptr) {
            node_ptr = std::make_unique<Node>(key, value);
            size++;
        }
        else if (key < node_ptr->element.first) {
            insert(node_ptr->left_, key, value);
        }
        else if (key > node_ptr->element.first) {
            insert(node_ptr->right_, key, value);
        }
        else {
            node_ptr->element.second = value;
        }
    }

    int get(std::unique_ptr<Node>& node_ptr, int key) {
        if (node_ptr == nullptr) {
            return -1;
        }
        if (key < node_ptr->element.first) {
            return get(node_ptr->left_, key);
        }
        if (key > node_ptr->element.first) {
            return get(node_ptr->right_, key);
        }
        return node_ptr->element.second;
    }

    Node* min(Node* current_node) const {
        if (current_node == nullptr) {
            return nullptr;
        }
        while (current_node->left_ != nullptr) {
            current_node = current_node->left_.get();
        }
        return current_node;
    }

    Node* max(Node* current_node) const {
        if (current_node == nullptr) {
            return nullptr;
        }
        while(current_node->right_ != nullptr) {
            current_node = current_node->right_.get();
        }
        return current_node;
    }

    void remove(std::unique_ptr<Node>& node_ptr, int key) {
        if (node_ptr == nullptr) {
            return;
        }
        else if (key < node_ptr->element.first) {
            remove(node_ptr->left_, key);
        }
        else if (key > node_ptr->element.first) {
            remove(node_ptr->right_, key);
        }
        else if (node_ptr->left_ != nullptr && node_ptr->right_ != nullptr) {
            node_ptr->element = min(node_ptr->right_.get())->element;
            remove(node_ptr->right_, node_ptr->element.first);
        }
        else if (node_ptr->left_ != nullptr) {
            node_ptr = std::move(node_ptr->left_);
            size--;   
        }
        else if (node_ptr->right_ != nullptr) {
            node_ptr = std::move(node_ptr->right_);
            size--;
        }
        else {
            node_ptr.reset();
        }
    }

public:
    TreeMap() {}

    void insert(int key, int val) {
        insert(root_, key, val);
    }

    int get(int key) {
        return get(root_,key);
    }

    int getMin() {
        Node* ptr = min(root_.get());
        return (ptr == nullptr) ? -1 : ptr->element.second; 
    }

    int getMax() {
        Node* ptr = max(root_.get());
        return (ptr == nullptr) ? -1 : ptr->element.second;
    }

    void remove(int key) {
        remove(root_, key);
    }

    std::vector<int> getInorderKeys() {
        std::stack<Node*> s {};
        std::vector<int> keys;
        keys.reserve(size);
        Node* current = root_.get();
        while (current != nullptr || !s.empty()) {
            if (current != nullptr) {
                s.push(current);
                current = current->left_.get();
            }
            else {
                current = s.top();
                s.pop();
                keys.emplace_back(current->element.first);
                current = current->right_.get();
            }
        }
        return keys;
    }
};