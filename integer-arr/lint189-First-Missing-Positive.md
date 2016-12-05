---
title: lint189-First-Missing-Positive
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# source

[189 First Missing Positive ](http://www.lintcode.com/en/problem/first-missing-positive/)


# solution 

## hash

```cpp
    int firstMissingPositive(vector<int> A) {
        // write your code here
        int ret = 1;
        vector<bool> B(2 * A.size() + 1, false);
        for (int i = 0; i < A.size(); i++)
            if (A[i] >0)
                B[A[i]] = true;
        for (int i = 1; i < B.size(); i++)
            if (B[i] == false)
                return i;
        return ret;
    }

```

## bucket sort


