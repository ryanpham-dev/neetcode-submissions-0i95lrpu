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
        std::unordered_map<Node*, Node*> connectedMap{};
        if (node == nullptr) {
            return nullptr;
        }
        std::stack<Node*> frontier{};
        frontier.push(node);
        while (!frontier.empty()) {
            Node* current = frontier.top();
            frontier.pop();
            if (!connectedMap.contains(current)) {
                connectedMap[current] = new Node(current->val);
            }

            for (const auto& neighbor : current->neighbors) {
                if (!connectedMap.contains(neighbor)) {
                    frontier.push(neighbor);
                    connectedMap[neighbor] = new Node(neighbor->val);
                }
                connectedMap[current]->neighbors.push_back(connectedMap[neighbor]);
            }
        }
        return connectedMap[node];
    }
};