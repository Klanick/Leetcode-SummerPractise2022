#include <iostream>
#include <vector>

/**Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    static std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> vec;
        addInRightSideView(root, vec, 0);
        return vec;
    }

    static void addInRightSideView(TreeNode* root, std::vector<int> & rightSight, int depth) {
        if (root != nullptr) {
            if (rightSight.size() <= depth) {
                rightSight.push_back(root->val);
            }

            addInRightSideView(root->right, rightSight, depth + 1);
            addInRightSideView(root->left, rightSight, depth + 1);
        }
    }
};

int main() {
    /** Put your argument instead of testTreeNode */
    TreeNode testTreeNode = TreeNode(10);
    std::vector<int> res = Solution::rightSideView(& testTreeNode);
    for (auto x : res) {
        std::cout << x << " ";
    }
    return 0;
}