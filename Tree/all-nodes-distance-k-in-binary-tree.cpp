class Solution {
public:
    // Function to mark parents for each node using BFS
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTra) {
        queue<TreeNode*> q;
        q.push(root);
        parentTra[root] = nullptr; // Parent of root is nullptr
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parentTra[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentTra[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTra;
        markParent(root, parentTra); // Populate parent mapping

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int current_level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (current_level == k) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            current_level++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (parentTra[node] && !visited[parentTra[node]]) {
                    q.push(parentTra[node]);
                    visited[parentTra[node]] = true;
                }
            }
        }
        return {}; // Return empty vector if no nodes found at distance k
    }
};