#include<stdio.h>

#include "InverseKthNodeInList.h"

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution2 s2;
    s2.getKthFromEnd(node1, 2);

    return 0;
}