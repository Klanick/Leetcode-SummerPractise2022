package day_3;

import java.util.Objects;

public class Solution {
    private static class FirstAbleTreeNode extends TreeNode {
        int firstVal;

        FirstAbleTreeNode(int val) {
            super(val);
        }
    }

    public TreeNode convertBST(TreeNode root) {
        return convertBSTAndFirstVal(root, 0);
    }

    public FirstAbleTreeNode convertBSTAndFirstVal(TreeNode root, int startVal) {
        if (Objects.isNull(root)) {
            return null;
        }
        FirstAbleTreeNode newRoot = new FirstAbleTreeNode(root.val);
        if (Objects.nonNull(root.right)) {
            FirstAbleTreeNode newRight = convertBSTAndFirstVal(root.right, startVal);
            newRoot.right = newRight;
            newRoot.val += newRight.firstVal;

        } else {
            newRoot.val += startVal;
        }
        newRoot.firstVal = newRoot.val;

        if (Objects.nonNull(root.left)) {
            FirstAbleTreeNode newLeft = convertBSTAndFirstVal(root.left, newRoot.val);
            newRoot.left = newLeft;
            newRoot.firstVal = newLeft.firstVal;
        }
        return newRoot;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

