#include<stdio.h>

#include "KGreatNumInBinaryTree.h"

int main()
{
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node1 = new TreeNode(1);
    node5->left = node3; node5->right = node6;
    node3->left = node2; node3->right = node4;
    node2->left = node1;

    Solution s;
    s.kthLargest(node5, 3);

    return 0;
}