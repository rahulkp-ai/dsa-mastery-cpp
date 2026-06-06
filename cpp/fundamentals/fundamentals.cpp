/**
 * C++20 Fundamentals for DSA
 * ============================
 * Covers: templates, smart pointers, lambdas,
 *         ranges, structured bindings, concepts
 */
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>
#include <ranges>
#include <numeric>

// ===== TEMPLATES =====
template<typename T>
T maxOf(T a, T b) { return (a > b) ? a : b; }

// ===== CONCEPTS (C++20) =====
template<std::integral T>
T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }

// ===== LAMBDA & HIGHER-ORDER FUNCTIONS =====
void lambdaDemo() {
    std::vector<int> v = {5,2,8,1,9,3};

    // Sort with lambda
    std::sort(v.begin(), v.end(), [](int a, int b){ return a < b; });

    // Transform with lambda
    std::vector<int> squares;
    std::transform(v.begin(), v.end(), std::back_inserter(squares),
                   [](int x){ return x*x; });

    // C++20 Ranges
    auto filtered = v | std::views::filter([](int x){ return x > 4; });
    std::cout << "Values > 4: ";
    for (int x : filtered) std::cout << x << " ";
    std::cout << "\n";
}

// ===== SMART POINTERS =====
struct TreeNode {
    int val;
    std::shared_ptr<TreeNode> left, right;
    explicit TreeNode(int v) : val(v) {}
};

auto makeTree() {
    auto root = std::make_shared<TreeNode>(1);
    root->left = std::make_shared<TreeNode>(2);
    root->right = std::make_shared<TreeNode>(3);
    return root; // No manual delete needed!
}

int main() {
    std::cout << maxOf(3, 7) << "\n";       // 7
    std::cout << gcd(48, 18) << "\n";       // 6
    lambdaDemo();

    auto tree = makeTree();
    std::cout << "Root: " << tree->val << "\n"; // 1

    // Structured bindings (C++17/20)
    std::vector<std::pair<std::string,int>> data = {{"Alice",90},{"Bob",85}};
    for (auto& [name, score] : data)
        std::cout << name << ": " << score << "\n";

    return 0;
}
