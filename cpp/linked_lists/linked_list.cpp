/**
 * Linked List — C++20
 * =====================
 * Time: O(n) traversal, O(1) insert/delete at known node
 * Space: O(n)
 */
#include <iostream>
#include <memory>
#include <optional>

namespace dsa {

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int v, ListNode* n = nullptr) : val(v), next(n) {}
};

ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

bool hasCycle(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* mergeSorted(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) { curr->next = l1; l1 = l1->next; }
        else { curr->next = l2; l2 = l2->next; }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return dummy.next;
}

} // namespace dsa

#if !defined(UNIT_TESTING)
int main() {
    using namespace dsa;
    // Build: 1->2->3->4->5
    ListNode* head = nullptr;
    for (int i = 5; i >= 1; --i) head = new ListNode(i, head);

    std::cout << "Middle: " << findMiddle(head)->val << "\n"; // 3

    head = reverse(head);
    std::cout << "Reversed: ";
    for (auto* p = head; p; p = p->next) std::cout << p->val << " ";
    std::cout << "\n";

    return 0;
}
#endif // UNIT_TESTING
