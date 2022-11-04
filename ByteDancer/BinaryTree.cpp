#include "BinaryTree.h"

TreeNode* CreateBinaryTreeNode(int value)
{
    TreeNode* newNode = new TreeNode;
    newNode->val = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void ConnectNodes(TreeNode* pParentNode, TreeNode* pLeftChildNode, TreeNode* pRightChildNode)
{
    pParentNode->left = pLeftChildNode;
    pParentNode->right = pRightChildNode;
}

void DestroyBinaryTree(TreeNode* pRoot)
{
    if (pRoot == nullptr) return;
    if (pRoot->left != nullptr) {
        DestroyBinaryTree(pRoot->left);
    }
    if (pRoot->right != nullptr) {
        DestroyBinaryTree(pRoot->right);
    }
    delete pRoot;
    pRoot = nullptr;
}