/**
 * STL Reference Guide - C++20
 * ============================
 * Comprehensive STL data structures and algorithms.
 */
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

void vectorDemo() {
    vector<int> v = {3, 1, 4, 1, 5};
    v.push_back(9);                    // O(1) amortized
    v.insert(v.begin(), 0);            // O(n)
    sort(v.begin(), v.end());          // O(n log n)
    v.erase(unique(v.begin(), v.end()), v.end()); // Remove duplicates
    cout << "Vector size: " << v.size() << "\n";
}

void mapDemo() {
    map<string, int> m;                // Sorted, O(log n)
    unordered_map<string, int> um;     // Hash, O(1) avg

    m["alice"] = 1; m["bob"] = 2;
    um["charlie"] = 3;

    // Iterate in sorted order (map only)
    for (auto& [key, val] : m) {
        cout << key << ": " << val << "\n";
    }
}

void priorityQueueDemo() {
    // Max-heap (default)
    priority_queue<int> maxPQ;
    // Min-heap
    priority_queue<int, vector<int>, greater<int>> minPQ;

    for (int x : {3, 1, 4, 1, 5, 9}) {
        maxPQ.push(x);
        minPQ.push(x);
    }
    cout << "Max: " << maxPQ.top() << "\n"; // 9
    cout << "Min: " << minPQ.top() << "\n"; // 1
}

int main() {
    vectorDemo();
    mapDemo();
    priorityQueueDemo();

    // Useful STL algorithms
    vector<int> nums = {5, 3, 8, 1, 9, 2};
    cout << "Max: " << *max_element(nums.begin(), nums.end()) << "\n";
    cout << "Sum: " << accumulate(nums.begin(), nums.end(), 0) << "\n";

    sort(nums.begin(), nums.end());
    cout << "Sorted. Binary search for 8: "
         << binary_search(nums.begin(), nums.end(), 8) << "\n";

    return 0;
}
