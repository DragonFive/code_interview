---
title: lint110-minimum-path-sum
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lin110-minimum-path-sum](http://www.lintcode.com/en/problem/minimum-path-sum/)
# solution

```cpp
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        //下面开始进行遍历;
        vector<int> minSums = vector<int>(n, 0);
        //初始化第一行
        minSums[0] = grid[0][0];
        for (int i = 1; i<n;i++)
            minSums[i] = minSums[i-1] + grid[0][i];
        //接下来每一行都比较左边和上边哪个值比较大;
        for (int i =1; i < m; i++)
            for (int j = 0; j < n;j++)
                if (j > 0 && minSums[j] > minSums[j-1])
                    minSums[j] = minSums[j-1] + grid[i][j];
                else
                    minSums[j] += grid[i][j];
        return minSums[n-1];
    }

```
