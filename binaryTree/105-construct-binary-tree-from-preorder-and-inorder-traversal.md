---
title: 105-construct-binary-tree-from-preorder-and-inorder-traversal
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem
[105-construct-binary-tree-from-preorder-and-inorder-traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/#/description)

# solution
递归
```cpp
typedef vector<int>::iterator vi;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return NULL;
        return helper(preorder.begin(),preorder.end()-1,inorder.begin(),inorder.end()-1);
    }
    TreeNode *helper(vi b1, vi e1,vi b2,vi e2)
    {
        if (b1 == e1)
        {
            TreeNode *root = new TreeNode(*b1);
            return root;
        }
        //找到第一个的根节点;
        int val = *b1;
        vi i = b2;
        for(; i != e2+1; i ++)
        {
            if (*i == val)
                break;
        }
        TreeNode *root = new TreeNode(val);
        if (i != b2)
            root->left = helper(b1+1,b1+(i-b2),b2,i-1);
        if (i != e2)
            root->right= helper(b1+(i-b2)+1,e1,i+1,e2);
        return root;
    }

```

# similiar problem
[72-construct-binary-tree-from-inorder-and-postorder-traversal](http://www.lintcode.com/en/problem/construct-binary-tree-from-inorder-and-postorder-traversal/#)
# solution

```cpp
typedef vector<int>::iterator vi;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if (postorder.empty())
            return NULL;
        return helper(postorder.begin(),postorder.end()-1,inorder.begin(),inorder.end()-1);
    }
    TreeNode *helper(vi b1, vi e1,vi b2,vi e2)
    {
        if (b1 == e1)
        {
            TreeNode *root = new TreeNode(*b1);
            return root;
        }
        //找到第一个的根节点;
        int val = *e1;
        vi i = b2;
        for(; i != e2+1; i ++)
        {
            if (*i == val)
                break;
        }
        TreeNode *root = new TreeNode(val);
        if (i != b2)
            root->left = helper(b1,b1+(i-b2)-1,b2,i-1);
        if (i != e2)
            root->right= helper(b1+(i-b2),e1-1,i+1,e2);
        return root;
    }
```

