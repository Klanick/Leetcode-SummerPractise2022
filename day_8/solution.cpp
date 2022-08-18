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
    static std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> levels;
        addLevelOrder(root, levels, 0);
        return levels;
    }

    static void addLevelOrder(TreeNode* root, std::vector<std::vector<int>> & levels, int depth) {
        if (root == nullptr) {
            return;
        }
        if (levels.size() <= depth) {
            levels.push_back({root->val});
        } else {
            levels[depth].push_back(root->val);
        }
        addLevelOrder(root->left, levels, depth + 1);
        addLevelOrder(root->right, levels, depth + 1);
    }
};

int main() {
    /** Put your argument instead of testTreeNode */
    TreeNode testTreeNode = TreeNode(10);
    std::vector<std::vector<int>> res = Solution::levelOrder(& testTreeNode);
    for (const std::vector<int> & level : res) {
        for (int x : level) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
