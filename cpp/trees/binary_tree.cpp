/**
 * Binary Tree - C++20
 * ====================
 * Time:  O(n) for all traversals
 * Space: O(h) where h = height
 */
#include <iostream>
#include <vector>
#include <queue>
#include <optional>
#include <memory>

namespace dsa {

struct TreeNode {
    int val;
    std::shared_ptr<TreeNode> left, right;
    explicit TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

using NodePtr = std::shared_ptr<TreeNode>;

// Inorder traversal (Left → Root → Right)
std::vector<int> inorder(NodePtr root) {
    std::vector<int> result;
    std::function<void(NodePtr)> dfs = [&](NodePtr node) {
        if (!node) return;
        dfs(node->left);
        result.push_back(node->val);
        dfs(node->right);
    };
    dfs(root);
    return result;
}

// Level order traversal (BFS)
std::vector<std::vector<int>> levelOrder(NodePtr root) {
    if (!root) return {};
    std::vector<std::vector<int>> result;
    std::queue<NodePtr> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        std::vector<int> level;
        for (int i = 0; i < size; ++i) {
            auto node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

int maxDepth(NodePtr root) {
    if (!root) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

} // namespace dsa

int main() {
    using namespace dsa;
    auto root = std::make_shared<TreeNode>(1);
    root->left  = std::make_shared<TreeNode>(2);
    root->right = std::make_shared<TreeNode>(3);
    root->left->left  = std::make_shared<TreeNode>(4);
    root->left->right = std::make_shared<TreeNode>(5);

    auto io = inorder(root);
    std::cout << "Inorder: ";
    for (int v : io) std::cout << v << " ";
    std::cout << "\nDepth: " << maxDepth(root) << "\n";
    return 0;
}
