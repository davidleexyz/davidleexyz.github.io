
struct ListNode {
  int value;
  ListNode* next;
};


// 注意添加一个虚拟头节点会方便很多
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* l = head;
        ListNode* r = nullptr;
        ListNode* h = nullptr;
        while (l != nullptr && l->next != nullptr) {
            ListNode* first = l;
            ListNode* second = l->next;
            l = second->next;

            first->next = nullptr;
            second->next = first;
            
            if (r == nullptr) {
                r = first;
            } else {
                r->next = second;
                r = first;
            }

            if (h == nullptr) {
                h = second;
            }
        }

        if (l != nullptr) {
            if (r == nullptr) {
                h = head;
            } else {
                r->next = l;
            }
        }

        return h;
    }
};