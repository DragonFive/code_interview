---
title: lint125-backpack-ii
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lint125-backpack-ii](http://www.lintcode.com/en/problem/backpack-ii/)
# solution
这是0-1背包问题的解法
```
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        vector<int> result(m+1, 0);
        int len = A.size();
        for (int i = 0; i< len; i++)
            for (int j = m; j > 0; j--)
                if (A[i] <= j && result[j] < result[j - A[i]] + V[i])
                    result[j] = result[j - A[i]] + V[i];
        return result[m];
    }
```