/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
*/
#include<unordered_map>
#include<stdio.h>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 typedef TreeNode BinaryTreeNode;

 BinaryTreeNode* CreateBinaryTreeNode(int value)
 {
     BinaryTreeNode* newNode = new BinaryTreeNode;
     newNode->val = value;
     newNode->left = NULL;
     newNode->m_pRight = NULL;
     return newNode;
 }

 void ConnectNodes(BinaryTreeNode* pParentNode, BinaryTreeNode* pLeftChildNode, BinaryTreeNode* pRightChildNode)
 {
     pParentNode->m_pLeft = pLeftChildNode;
     pParentNode->m_pRight = pRightChildNode;
 }

 void DestroyBinaryTree(BinaryTreeNode* pRoot)
 {
     if (pRoot == NULL) return;
     if (pRoot->m_pLeft != NULL) {
         DestroyBinaryTree(pRoot->m_pLeft);
     }
     if (pRoot->m_pRight != NULL) {
         DestroyBinaryTree(pRoot->m_pRight);
     }
     delete pRoot;
     pRoot = NULL;
 }
 
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

int main()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectNodes(pNode1, pNode2, pNode3);
    ConnectNodes(pNode2, pNode4, pNode5);

    int result = sumNumbers(pNode1);

    DestroyBinaryTree(pNode1);
    return 0;
}