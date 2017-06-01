---
title: lint92-backpack
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem

[lint92-backpack](http://www.lintcode.com/en/problem/backpack/)
# solution

```
    int backPack(int m, vector<int> A) {
        // write your code here
        vector<vector<int> > result = vector<vector<int> >(m+1, vector<int>(A.size()+1, 0) );
        //然后进行双循环
        for (int i = 0; i < m+1; i++)//物品重量累加
            for (int j = 1; j < A.size() + 1; j++)//物品数目累加
                if (A[j] <= i)
                    result[i][j] = result[i][j-1] > result[i-A[j]][j-1] + A[j]?result[i][j-1]: result[i-A[j]][j-1] + A[j];
                else
                    result[i][j] = result[i][j-1];
        return result[m][A.size()];
        
    }
```