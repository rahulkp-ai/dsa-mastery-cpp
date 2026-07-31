#include "test_common.hpp"
#include "../../cpp/linked_lists/linked_list.cpp"

static dsa::ListNode* build_list(const std::vector<int>& values) {
    dsa::ListNode* head = nullptr;
    for (int i = static_cast<int>(values.size()) - 1; i >= 0; --i) {
        head = new dsa::ListNode(values[i], head);
    }
    return head;
}

static void free_list(dsa::ListNode* head) {
    while (head) {
        dsa::ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    auto* head = build_list({1, 2, 3, 4});
    CHECK_EQ(dsa::findMiddle(head)->val, 3);
    auto* rev = dsa::reverse(head);
    CHECK_EQ(rev->val, 4);
    free_list(rev);
    return 0;
}
