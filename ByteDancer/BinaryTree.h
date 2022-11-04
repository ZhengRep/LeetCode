#pragma once

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* CreateBinaryTreeNode(int value);
void ConnectNodes(TreeNode* pParentNode, TreeNode* pLeftChildNode, TreeNode* pRightChildNode);
void DestroyBinaryTree(TreeNode* pRoot);