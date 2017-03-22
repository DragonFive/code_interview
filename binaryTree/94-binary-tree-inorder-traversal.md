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

迭代法
```cpp
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *cur = root;
        while (!st.empty())
        {
            while (cur->left)
            {
                st.push(cur->left);
                cur = cur->left;
            }
            st.pop();
            result.push_back(cur->val);
            //访问右节点;
            while (cur->right == NULL && !st.empty())
            {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
            }
            if (cur->right)
            {
                st.push(cur->right);
                cur = cur->right;
            }
        }
        return result;
    }
```

