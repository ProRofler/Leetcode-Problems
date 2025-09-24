#include <cmath>
#include <iostream>
#include <memory>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* headIt = new ListNode(0);

    ListNode* dummy = new ListNode(0);

    head = headIt;

    int carry = 0;

    while (l1 != dummy || l2 != dummy || carry != 0) {
      int sum = 0;
      int val_1 = l1 == nullptr ? 0 : l1->val;
      int val_2 = l2 == nullptr ? 0 : l2->val;

      sum = val_1 + val_2 + carry;
      carry = sum >= 10 ? 1 : 0;

      headIt->val = sum >= 10 ? sum % 10 : sum;

      if (l1->next || l2->next || carry != 0) {
        headIt->next = new ListNode();
        headIt = headIt->next;
      }

      if (l1->next) {
        l1 = l1->next;
      } else {
        l1 = dummy;
      }

      if (l2->next) {
        l2 = l2->next;
      } else {
        l2 = dummy;
      }
    }

    return head;
  }
};

void deleteList(ListNode* head) {
  ListNode* current = head;
  while (current != nullptr) {
    ListNode* next = current->next;
    delete current;
    current = next;
  }
}

int main() {
  const auto sol = std::make_unique<Solution>;

  ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3, nullptr)));
  ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4, nullptr)));

  sol().get()->addTwoNumbers(l1, l2);

  deleteList(l1);
  deleteList(l2);

  return 0;
}