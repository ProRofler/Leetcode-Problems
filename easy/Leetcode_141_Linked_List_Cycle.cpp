#include <math>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    int i = 1;

    while (head) {
      if (i > pow(10, 4)) return true;

      i++;
      head = head->next;
    }

    return false;
  }
}; // Ultra shitty brute force solution

class TwoPtrSolution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;

        ListNode *i = head;
        ListNode *j = head;

        while(i && i->next){
            i = i->next->next;
            j = j->next;
            if(i==j) return true;    
        }

        return false;
    }
};