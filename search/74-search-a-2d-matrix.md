---
title: 74-search-a-2d-matrix
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem

[74 search a 2d matrix](https://leetcode.com/problems/search-a-2d-matrix/?tab=Description)

# solution 

```cpp
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int i = -1, j = rows * cols;
        while (i + 1 < j)
        {
            int mid = i + (j - i)/2;
            if (matrix[mid / cols][mid % cols] < target)
                i = mid;
            else
                j = mid;
        }
        if ( j < rows * cols && matrix[j / cols][j % cols] == target)
            return true;
        return false;
    }
```