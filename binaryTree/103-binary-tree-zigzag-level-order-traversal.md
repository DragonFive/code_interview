---
title: 103-binary-tree-zigzag-level-order-traversal
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem 
[103-binary-tree-zigzag-level-order-traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/#/description)

# solution
双栈交叉换序法
```cpp
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode *> q,s;
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        q.push(root);
        while (!q.empty())
        {
            vector<int> r;
            while(!q.empty())
            {
                TreeNode *tmp = q.top();
                r.push_back(tmp->val);
                q.pop();
                if (tmp->left)
                    s.push(tmp->left);
                if (tmp->right)
                    s.push(tmp->right);
            }
            if (!r.empty())
                res.push_back(r);
            vector<int> t;
            while(!s.empty())
            {
                TreeNode *tmp = s.top();
                s.pop();
                t.push_back(tmp->val);
                if (tmp->right)
                    q.push(tmp->right);
                if (tmp->left)
                    q.push(tmp->left);
                                
            }
            if (!t.empty())
                res.push_back(t);
        }
        return res;
    }

```
