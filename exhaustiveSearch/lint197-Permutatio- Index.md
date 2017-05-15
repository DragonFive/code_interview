---
title: lint197-Permutatio- Index
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# source

[lint197-Permutatio- Index](http://www.lintcode.com/en/problem/permutation-index/)



# solution
```
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        if (A.empty())
            return 0;
        long long factor = 1;
        //遍历所有的位数;
        long long result = 1;
        for (int i = A.size() - 1; i >= 0; i--)
        {
            long long rank = 0;
            for (int j = i + 1; j < A.size(); j++)
                if (A[i] > A[j])
                    rank++ ;
            result += rank * factor;
            factor *= (A.size() - i);
        }
        return result;
    }
```

# reference

[permutation_index](https://algorithm.yuanbin.me/zh-hans/exhaustive_search/permutation_index.html)