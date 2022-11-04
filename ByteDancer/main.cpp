
#include "PathSumInBinaryTree.h"

int main()
{
    TreeNode* pNode1 = CreateBinaryTreeNode(1);
    TreeNode* pNode2 = CreateBinaryTreeNode(2);
    TreeNode* pNode3 = CreateBinaryTreeNode(3);
    TreeNode* pNode4 = CreateBinaryTreeNode(4);
    TreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectNodes(pNode1, pNode2, pNode3);
    ConnectNodes(pNode2, pNode4, pNode5);

    Solution2 solution2;
    int result = solution2.pathSum(pNode1, 6);

    DestroyBinaryTree(pNode1);
    return 0;
}