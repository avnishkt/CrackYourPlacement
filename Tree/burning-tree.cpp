class Solution {
public:
    Node* markParent(Node* root, unordered_map<Node*, Node*>& parentTra, int target) {
        queue<Node*> q;
        q.push(root);
        parentTra[root] = nullptr;
        Node* temp = nullptr; // Parent of root is nullptr
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node->data == target)
                temp = node;
            if (node->left) {
                parentTra[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentTra[node->right] = node;
                q.push(node->right);
            }
        }
        return temp;
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentTra;
        Node* Target = markParent(root, parentTra, target); // Populate parent mapping

        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(Target);
        visited[Target] = true;

        int current_level = 0;
        while (!q.empty()) {
            int size = q.size();
            bool level_increase = false;
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                    level_increase = true;
                }
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                    level_increase = true;
                }
                if (parentTra[node] && !visited[parentTra[node]]) {
                    q.push(parentTra[node]);
                    visited[parentTra[node]] = true;
                    level_increase = true;
                }
            }
            if (level_increase) {
                current_level++;
            }
        }
        return current_level; // Return the time taken to burn the entire tree
    }
};