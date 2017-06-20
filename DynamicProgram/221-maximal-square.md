---
title: 221-maximal-square 
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[221-maximal-square](https://leetcode.com/problems/maximal-square/#/description)
# solution
### 最粗糙的方法，复杂度比较高，但是空间复杂度低; 
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

### code analysis
时间复杂度为o(n^3)

## solution2 动态规划
```cpp
    int maximalSquare(vector<vector<char>>& matrix) {
        //对每一个点记忆从它出发的max值，如果不符合就算了，符合的话;
            if (matrix.empty() || matrix[0].size() == 0)
                return 0;
            int m = matrix.size(), n = matrix[0].size();
            int maxSize = 0;
            vector<vector<int> > result(m, vector<int>(n, 0));
            for (int i = 0; i < n; i++)
                if (matrix[0][i] == '1')
                {
                    result[0][i] = 1;maxSize = 1;
                }
            for (int i = 0; i < m; i++)
                if (matrix[i][0] == '1')
                {    result[i][0] = 1;maxSize = 1;}
            
            for (int i = 1; i < m; i++)
                for (int j = 1; j < n; j++)
                {
                    if (matrix[i][j] == '1')
                        result[i][j] = min(min(result[i-1][j-1], result[i-1][j]),result[i][j-1])+1;
                    else
                        result[i][j] = 0;
                    maxSize = max(maxSize, result[i][j]);
                }
            return maxSize*maxSize;
    }
```

## solution3 动态规划+单维数组

```cpp
    int maximalSquare(vector<vector<char>>& matrix) {
        //对每一个点记忆从它出发的max值，如果不符合就算了，符合的话;
            if (matrix.empty() || matrix[0].size() == 0)
                return 0;
            int m = matrix.size(), n = matrix[0].size();
            int maxSize = 0;
            vector<int> result(n, 0);
            for (int i = 0; i < n; i++)
                if (matrix[0][i] == '1')
                {
                    result[i] = 1;maxSize = 1;
                }
            for (int i = 1; i < m; i++)
            {
                int pre = result[0];
                result[0] = matrix[i][0] == '1'?1:0;
                maxSize = max(result[0], maxSize);
                for (int j = 1; j < n; j++)
                {
                    int temp = result[j];
                    if (matrix[i][j] == '1')
                        result[j] = min(min(pre, result[j]),result[j-1])+1;
                    else
                        result[j] = 0;
                    maxSize = max(maxSize, result[j]);
                    pre = temp;
                }
            }
            return maxSize*maxSize;
    }
```
