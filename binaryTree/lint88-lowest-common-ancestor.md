---
title: lint88-lowest-common-ancestor
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem

[lint88-lowest-common-ancestor](http://www.lintcode.com/en/problem/lowest-common-ancestor/)
# solution
先序递归法;自低向上
```cpp
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        bool findans = false;
        return findChild(root,A,B,findans);
    }
    TreeNode * findChild(TreeNode *root, TreeNode *A, TreeNode *B, bool &findAns)
    {
        if (root == NULL)
            return NULL;
        bool findRoot = false;
        if (root == A || root == B)
        {
            findAns = true;
            if (A==B)
            {
                return root;
            }
            findRoot = true;
            
        }
        bool leftAns = false, rightAns = false;
        TreeNode* leftRes  = findChild(root->left,A,B,leftAns ) ;
        TreeNode* rightRes = findChild(root->right,A,B,rightAns) ;
        if (leftRes!=NULL || rightRes!=NULL)
        {
            findAns = true;
            return leftRes==NULL?rightRes:leftRes;
        }
        if (leftAns || rightAns ) 
        {
            findAns = true;
            if (findRoot || leftAns&&rightAns)
                return root;
        }
        return NULL;
    }
```