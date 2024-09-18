/*
二叉搜索树的查找算法:

在二叉搜索树b中查找x的过程为：

1. 若b是空树，则搜索失败，否则：
2. 若x等于b的根节点的数据域之值，则查找成功；否则：
3. 若x小于b的根节点的数据域之值，则搜索左子树；否则：
4. 查找右子树。

*/

// 在根指针T所指二叉查找树中递归地查找其关键字等于key的数据元素，若查找成功，
// 则指针p指向該数据元素节点，并返回TRUE，否则指针指向查找路径上访问的最终
// 一个节点并返回FALSE，指针f指向T的双亲，其初始调用值为NULL
#include <iostream>
using namespace std;

// 定义二叉搜索树节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 二叉搜索树查找
TreeNode* searchBST(TreeNode* root, int target) {
    if (!root || root->val == target) {
        return root;
    }
    if (target < root->val) {
        return searchBST(root->left, target);
    } else {
        return searchBST(root->right, target);
    }
}

// 辅助函数，用于创建二叉搜索树
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

int main() {
    // 创建二叉搜索树
    TreeNode* root = NULL;
    int values[] = {5, 3, 7, 1, 4, 6, 8};
    for (int val : values) {
        root = insertIntoBST(root, val);
    }

    // 查找目标值
    int target = 6;
    TreeNode* result = searchBST(root, target);

    if (result) {
        cout << "Element " << target << " found in the BST." << endl;
    } else {
        cout << "Element " << target << " not found in the BST." << endl;
    }

    return 0;
}