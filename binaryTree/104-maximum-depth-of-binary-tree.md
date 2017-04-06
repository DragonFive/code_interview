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
    }
	
	```
	
	广度优先遍历 用队列
	```cpp
	    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        if (root == NULL)
            return 0;
        queue<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            int qsize = st.size();
            maxDepth++;
            while (qsize--)
            {
                TreeNode * fa = st.front();
                st.pop();
                if (fa->left||fa->right)
                {
                    if (fa->left)
                        st.push(fa->left);
                    if (fa->right)
                        st.push(fa->right);
                }
            }
        }
        return maxDepth;
    }
	```
	
	
