#pragma once
#include<unordered_set>

using namespace std;

 //Definition for singly - linked list.
  struct ListNode {
      int val;
      ListNode* next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution1 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;

        ListNode* pA = headA, * pB = headB;
        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }
        if (!pA) return nullptr;

        return pA;
    }
};

class Solution2 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;

        unordered_set<ListNode*> nodePtrSet;
        ListNode* pMove = headA;
        while (pMove) {
            nodePtrSet.insert(pMove);
            pMove = pMove->next;
        }
        pMove = headB;
        while (pMove) {
            if (nodePtrSet.count(pMove)) {
                return pMove;
            }
            pMove = pMove->next;
        }

        return nullptr;
    }
};