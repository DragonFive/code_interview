---
title: 240-search-a-2d-matrix2
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem
[240-search-a-2d-matrix2](https://leetcode.com/problems/search-a-2d-matrix-ii/?tab=Description)
## similiar problem

[74-search-a-2d-matrix](https://github.com/DragonFive/Leetcode/blob/master/search/74-search-a-2d-matrix.md)

# solution
逐层遍历法
时间复杂度为O(mlogn)
```cpp
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] > target)
                break;
            if (matrix[i][cols - 1] < target)
                continue;
            if (searchRow(matrix[i], target))
                return true;
        }
        return false;
    }
    bool searchRow(vector<int> &row, int target)
    {
        if (row.empty())
            return false;
        const int len = row.size();
        int i = -1, j = len;
        while (i + 1 < j)
        {
            int k = i + (j - i) / 2;
            if (row[k]  < target)
                i = k;
            else
                j = k;
        } 
        if (j != len && row[j] == target)
            return true;
        return false;
    }
```
