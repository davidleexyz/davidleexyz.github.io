
struct ListNode {
  int value;
  ListNode* next;
  ListNode() : value(0), next(nullptr) {} 
};

// 迭代法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* reverse = nullptr;
        ListNode* tmp = nullptr;
        while (head != nullptr) {
            tmp = head;
            head = head->next;
            tmp->next = reverse;
            reverse = tmp;
        }

        return reverse;
    }
};

// 递归法
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    return reverse(nullptr, head);
  }

  ListNode* reverse(ListNode* pre, ListNode* cur) {
    if (cur == nullptr) return pre;
    ListNode* tmp = cur->next;
    
    cur->next = pre;
    pre = cur;
    return reverse(pre, tmp);
  }
};