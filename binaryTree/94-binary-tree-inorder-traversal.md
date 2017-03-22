---
title: 94-binary-tree-inorder-traversal
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem
[94-binary-tree-inorder-traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/#/description)
# solution

```cpp
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderVisit(root,result);
        return result;
    }
    void inorderVisit(TreeNode*node,vector<int> &ret)
    {
        if(node)
        {
            inorderVisit(node->left,ret);
            ret.push_back(node->val);
            inorderVisit(node->right,ret);
        }
    }
```