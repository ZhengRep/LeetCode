#pragma once
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    
};
class Solution1 {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head) return nullptr;

        //get nodes number
        ListNode* pMove = head;
        int num = 0;
        while (pMove) {
            num++;
            pMove = pMove->next;
        }
        if (num <= k) return head;

        num -= k;
        pMove = head;
        while (num--) {
            pMove = pMove->next;
        }
        return pMove;
    }
};

class Solution2 {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head) return nullptr;

        ListNode* former = head, * latter = head;
        while (k-- && former) {
            former = former->next;
        }
        if (k != 0) return head;
        while (former) {
            former = former->next;
            latter = latter->next;
        }
        return latter;
    }
};