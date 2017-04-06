---
title: 110-balanced-binary-tree
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem
[110-balanced-binary-tree](https://leetcode.com/problems/balanced-binary-tree/#/description)

# solution
```cpp
    bool isBalanced(TreeNode* root) {
        if (helper(root) == -1)
            return false;
        return true;
    }
    int helper(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int leftDepth  = helper(root->left );
        int rightDepth = helper(root->right);
        if (leftDepth == -1 || rightDepth == -1)
            return -1;
        if (leftDepth == rightDepth || rightDepth == leftDepth+1 || leftDepth == rightDepth+1 )
            return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
        return -1;
    }
```