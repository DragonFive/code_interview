---
title: 145-binary-tree-postorder-traversal
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---
[TOC]

# problem
[145-binary-tree-postorder-traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/#/description)

# solution
## 递归法
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

## 迭代法 + 反序法
```cpp
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *cur = root;
        while (!st.empty())
        {
            cur = st.top();
            result.push_back(cur->val);
            st.pop();
            if (cur->left)
                st.push(cur->left);
            if (cur->right)
                st.push(cur->right);
        }
        //下面对result，进行reverse;
        reverse(result.begin(),result.end());
        return result;
    }
```

## 迭代法  记录孩子访问过

```cpp
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        st.push(root);
        while (!st.empty())
        {
            if (!cur->left && !cur->right || pre != NULL && (pre == cur->left || pre == cur->right) )//无左右孩子，或者都访问过；
            {//则访问当前节点;
                st.pop();
                result.push_back(cur->val);
                pre = cur;
                if (!st.empty())
                    cur = st.top();
            }
            else
            {
                if (cur->right)
                {
                    st.push(cur->right);
                }
                if (cur->left)
                {
                    st.push(cur->left);
                }
                cur = st.top();
            }
        }
        return result;
    }
```