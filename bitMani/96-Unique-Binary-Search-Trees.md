---
title: 96-Unique-Binary-Search-Trees 
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem
[96-Unique-Binary-Search-Trees](https://leetcode.com/problems/unique-binary-search-trees/#/description)

# solution

```cpp
    int numTrees(int n) {
        
        if (n <=2)
            return n;
        int sum = 0;
        sum = 2*numTrees(n-1);
        for (int i = 1; i < n - 1; i++)
        {
            sum = sum + numTrees(i) * numTrees(n -1 - i);
        }
        return sum;

```