/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        int lengthB = 0;
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        while (tmpA != nullptr) {
            lengthA++;
            tmpA = tmpA->next;
        }

        while (tmpB != nullptr) {
            lengthB++;
            tmpB = tmpB->next;
        }

        tmpA = headA;
        tmpB = headB;
        if (lengthA > lengthB) {
            int n = lengthA - lengthB;
            while(n > 0 && tmpA != nullptr) {
                n--;
                tmpA = tmpA->next;
            }
        } else {
            int n = lengthB - lengthA;
            while(n > 0 && tmpB != nullptr) {
                n--;
                tmpB = tmpB->next;
            }
        }

        while(tmpA != nullptr && tmpB != nullptr) {
            if (tmpA == tmpB) {
                return tmpA;
            }
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        return nullptr;
    }
};