/*
����һ���������ĸ��ڵ� root ������ÿ���ڵ㶼�����һ�� 0 �� 9 ֮������֡�

ÿ���Ӹ��ڵ㵽Ҷ�ڵ��·��������һ�����֣�

���磬�Ӹ��ڵ㵽Ҷ�ڵ��·�� 1 -> 2 -> 3 ��ʾ���� 123 ��
����Ӹ��ڵ㵽Ҷ�ڵ����ɵ� ��������֮�� ��

Ҷ�ڵ� ��ָû���ӽڵ�Ľڵ㡣
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
