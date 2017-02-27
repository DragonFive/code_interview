---
title: 74-search-a-2d-matrix
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem

[74 search a 2d matrix](https://leetcode.com/problems/search-a-2d-matrix/?tab=Description)

# solution 
 ## 折半查找法
 时间复杂度为O(logmn)
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

## 从右上到左下
时间复杂度为O(m+n)
```cpp
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( matrix.empty() || matrix[0].empty() )
            return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int i = 0, j = cols -1;
        while ( i < rows && j >=0 )
        {
            if ( matrix[i][j] == target)
                return true;
            if ( matrix[i][j] < target )
                i += 1;
            else
                j -=1;
        }
        return false;
    }
```