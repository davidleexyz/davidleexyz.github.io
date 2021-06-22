struct ListNode {
  int value;
  ListNode* next;
  ListNode(int value) : value(value), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* begin = dummyHead;
        ListNode* end = dummyHead;

        while (end->next != nullptr) {
            end = end->next;
            n--;
            if (n < 0) {
                begin = begin->next;
            }
        }

        ListNode* tmp = begin->next;
        begin->next = tmp->next;
        delete tmp;

        return dummyHead->next;
    }
};