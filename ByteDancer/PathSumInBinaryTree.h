/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
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
    //what is prefex sum
    unordered_map<long long, int> prefexSum; //sum, index -> to record prefex sum root->p1->p2->pk
    int DfsAndUpdatePrefexMap(TreeNode* root, long long preSum, int targetSum) {
        if (!root) return 0;
        long long currSum = preSum + root->val;
        int ret = 0;
        if (prefexSum.count(currSum - targetSum)) {
            ret = prefexSum[currSum - targetSum];
        }

        prefexSum[currSum]++;
        ret += DfsAndUpdatePrefexMap(root->left, currSum, targetSum);
        ret += DfsAndUpdatePrefexMap(root->right, currSum, targetSum);
        prefexSum[currSum]--;

        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefexSum[0] = 1; //
        return DfsAndUpdatePrefexMap(root, 0, targetSum);
    }
};

