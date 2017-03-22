---
title: 145-binary-tree-postorder-traversal
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem
[145-binary-tree-postorder-traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/#/description)

# solution

```cpp
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;
        posterVisit(root,result);
        return result;
    }
    void posterVisit(TreeNode *root, vector<int> &ret)
    {
        if (root)
        {
            posterVisit(root->left ,ret);
            posterVisit(root->right,ret);
            ret.push_back(root->val);
        }
    }
```