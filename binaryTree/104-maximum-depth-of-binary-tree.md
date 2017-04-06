---
title: 104-maximum-depth-of-binary-tree
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem
[104-maximum-depth-of-binary-tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/#/description)

# solution

递归法：
```cpp
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
    }```
