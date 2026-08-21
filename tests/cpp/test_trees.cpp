#include "test_common.hpp"
#include "../../cpp/trees/binary_tree.cpp"

int main()
{
    auto root = std::make_shared<dsa::TreeNode>(1);
    root->left = std::make_shared<dsa::TreeNode>(2);
    root->right = std::make_shared<dsa::TreeNode>(3);
    root->left->left = std::make_shared<dsa::TreeNode>(4);
    root->left->right = std::make_shared<dsa::TreeNode>(5);
    CHECK_EQ((dsa::inorder(root)), (std::vector<int>{4, 2, 5, 1, 3}));
    CHECK_EQ((dsa::levelOrder(root)), (std::vector<std::vector<int>>{{1}, {2, 3}, {4, 5}}));
    CHECK_EQ((dsa::maxDepth(root)), (3));
    return 0;
}
