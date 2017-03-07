---
title: 2017-3-7-lint82single-number
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem
[82single-number/](http://www.lintcode.com/en/problem/single-number/)

# solution 

```cpp
    int singleNumber(vector<int> &A) {
        // write your code here
        if (A.empty())
            return 0;
        int result = A[0];
        for (int i = 1; i < A.size(); i++)
        {
            result = result ^ A[i];
        }
        return result;
    }
```