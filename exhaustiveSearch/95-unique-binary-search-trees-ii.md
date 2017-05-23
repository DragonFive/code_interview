---
title: 95-unique-binary-search-trees-ii
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---
# problem
[95-unique-binary-search-trees-ii](https://leetcode.com/problems/unique-binary-search-trees-ii/#/description)
## similiar problem

[96-Unique-Binary-Search-Trees](https://github.com/DragonFive/Leetcode/blob/master/bitMani/96-Unique-Binary-Search-Trees.md)

# solution

```
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> result;
        if (n == 0)
            return result;
        return helper(1, n);
    }
    vector<TreeNode *> helper(int start, int end)
    {
        vector<TreeNode *> result;
        if (start > end)
        {
            result.push_back(NULL);
            return result;
        }
        for (int i = start; i <= end; i++)
        {
            //把每个节点当作根节点来用一用;
            vector<TreeNode *> leftTree = helper(start, i-1);
            vector<TreeNode *> rightTree = helper(i+1, end);
            //把左右子树进行配对
            for (int j = 0; j < leftTree.size(); j++)
            {
                for (int k =0; k < rightTree.size(); k++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
```

# reference
[unique_binary_search_trees_ii](https://algorithm.yuanbin.me/zh-hans/exhaustive_search/unique_binary_search_trees_ii.html)