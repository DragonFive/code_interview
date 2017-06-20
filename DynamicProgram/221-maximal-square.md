---
title: 221-maximal-square 
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[221-maximal-square](https://leetcode.com/problems/maximal-square/#/description)
# solution
最粗糙的方法，复杂度比较高，但是空间复杂度低; 
```cpp
    int maximalSquare(vector<vector<char>>& matrix) {
        //对每一个点记忆从它出发的max值，如果不符合就算了，符合的话;
        if (matrix.empty() || matrix[0].size() == 0)
            return 0;
        int maxSize = 0, size = 0;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i <m; i++)
        {
            if (i+maxSize >= m)
                break;
            for (int j = 0; j < n; j++)
            {
                //对每一个元素进行测试;
                if (j+maxSize>=n)
                    break;
                size = maxSize;
                for (int k = maxSize; k < min(n-j, m-i) ; k++)//不要超出范围;
                    if (isAllOne(matrix, i, j, k))
                        size++;
                    else
                        break;
                maxSize = size;
            }
        }
        return maxSize*maxSize;
    }
    bool isAllOne(vector<vector<char>>& matrix, int m, int n, int maxSize)
    {
        for (int i = m; i <= m+maxSize; i++)
            for (int j = n; j <= n+maxSize; j++)
                if (matrix[i][j] == '0')
                    return false;
        return true;
    }
```

## code analysis
时间复杂度为o(n^3)
