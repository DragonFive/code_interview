---
title: lint245-subtree
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem

[lint245-subtree](http://www.lintcode.com/en/problem/subtree/#)

# solution

```cpp
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        //先找到root；
        if (T2 == NULL)
            return true;
        if (T1 == NULL)
            return false;
        if (sameTree(T1,T2))
            return true;
        return isSubtree(T1->left,T2) | isSubtree(T1->right,T2);
    }

    bool sameTree(TreeNode *T1, TreeNode *T2)
    {
        if (T1 == NULL && T2 == NULL)
            return true;
        if (T1 == NULL || T2 == NULL)
            return false;
        if (T1->val != T2->val)
            return false;
        if (sameTree(T1->left,T2->left) && sameTree(T1->right,T2->right))    
            return true;
        return false;
    }
```
