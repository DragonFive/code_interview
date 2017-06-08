---
title: lint111-climbing-stairs
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lint111-climbing-stairs](http://www.lintcode.com/en/problem/climbing-stairs/)

# solution
```cpp
    int climbStairs(int n) {
        // write your code here
        if (n < 2)
            return 1;
        vector<int> result(n+1, 0);
        result[0] = 1;
        result[1] = 1;
        for (int i = 2; i <= n; i++)
            result[i] = result[i-2] + result[i-1];
        return result[n];
    }

```