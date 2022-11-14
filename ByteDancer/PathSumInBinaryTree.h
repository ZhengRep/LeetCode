/*
����һ���������ĸ��ڵ� root ����һ������ targetSum ����ö�������ڵ�ֵ֮�͵��� targetSum �� ·�� ����Ŀ��

·�� ����Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��
*/
#pragma once
#include "BinaryTree.h"
#include<unordered_map>

using namespace std;
 
class Solution1 {
public:
    //violence to search result, every node as root to search
    //return child tree's path sum(left, right)
    //The param of targetsum is curent value to arithmetic
    int DfsGetPathSumFromCurrentRoot(TreeNode* root, long long targetSum) { //I ever think should have preValue, pathSum???
        if (!root) return 0;

        //get child path
        int ret = 0;
        if (root->val == targetSum) {
            ret++;
        }

        ret += root->left ? DfsGetPathSumFromCurrentRoot(root->left, targetSum - root->val) : 0; //must to leaf node
        ret += root->right ? DfsGetPathSumFromCurrentRoot(root->right, targetSum - root->val) : 0;

        return ret;



    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        int ret = 0;
        ret = DfsGetPathSumFromCurrentRoot(root, targetSum);

        ret += pathSum(root->left, targetSum);
        ret += pathSum(root->right, targetSum);
        return ret;
    }
};


class Solution2 {
public:
    //what is prefix sum
    unordered_map<long long, int> prefixSum; //sum, index -> to record prefix sum root->p1->p2->pk
    int DfsAndUpdateprefixMap(TreeNode* root, long long preSum, int targetSum) {
        if (!root) return 0;
        long long currSum = preSum + root->val;
        int ret = 0;
        if (prefixSum.count(currSum - targetSum)) {
            ret = prefixSum[currSum - targetSum];
        }

        prefixSum[currSum]++;
        ret += DfsAndUpdateprefixMap(root->left, currSum, targetSum);
        ret += DfsAndUpdateprefixMap(root->right, currSum, targetSum);
        prefixSum[currSum]--;

        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefixSum[0] = 1; //
        return DfsAndUpdateprefixMap(root, 0, targetSum);
    }
};

