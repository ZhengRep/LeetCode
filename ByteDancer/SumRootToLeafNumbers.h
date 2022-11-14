/*
给定一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。

每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。

叶节点 是指没有子节点的节点。
*/
#pragma once
#include "BinaryTree.h"
#include<deque>
using namespace std;

class Solution1 {
public:
    int BfsGetSum(TreeNode* root) {
        if (root == nullptr) return 0;

        deque<TreeNode*> nodesdeque;
        deque<int> valuesdeque;

        nodesdeque.push_back(root);
        valuesdeque.push_back(0);

        int sum = 0;
        while (!nodesdeque.empty()) {
            TreeNode* pNode = nodesdeque.front();
            nodesdeque.pop_front();
            int curentValue = valuesdeque.front() * 10 + pNode->val;
            valuesdeque.pop_front();

            if (!pNode->left && !pNode->right) {
                sum += curentValue;
            }
            if (pNode->left) {
                nodesdeque.push_back(pNode->left);
                valuesdeque.push_back(curentValue);
            }
            if (pNode->right) {
                nodesdeque.push_back(pNode->right);
                valuesdeque.push_back(curentValue);
            }
        }
        return sum;
    }

    int sumNumbers(TreeNode* root) {
        return BfsGetSum(root);
    }
};

class Solution2 {
public:
    int DfsAndSum(TreeNode* root, int preVal) {
        if (root == nullptr) return preVal;

        int currentValue = preVal * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) { //must be leaf node
            return currentValue;
        }
        else {
            int leftSum =  DfsAndSum(root->left, currentValue);
            int rightSum = DfsAndSum(root->right, currentValue);
            return  leftSum + rightSum;
        }
    }


    int sumNumbers(TreeNode* root) {
        //when counter leaf to sum
        int preVal = 0;
        return DfsAndSum(root, preVal);
    }
};
