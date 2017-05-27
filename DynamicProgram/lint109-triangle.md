---
title: lint109-triangle
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lint109-triangle](http://www.lintcode.com/en/problem/triangle/)

# solution
## 解法1,自上而下递归法
```
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        if (triangle.empty())
            return 0;
        return dfs(triangle, 0, 0);
    }
    int dfs(vector<vector<int> > &triangle, int i, int j)
    {
        if (i == triangle.size() - 1)//最后一行;
            return triangle[i][j];
        int left = dfs(triangle, i + 1, j);
        int right = dfs(triangle, i + 1, j+1);
        return left < right ? triangle[i][j] + left : triangle[i][j] + right;  
    }
```
### analysis

因为递归导致重复计算，所以会导致超时




