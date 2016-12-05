---
title: 41first-missing-positive
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# source

[41 first-missing-positive](https://leetcode.com/problems/first-missing-positive/)

## similiar problem 
[lint189-First-Missing-Positive.md](https://github.com/DragonFive/Leetcode/blob/master/integer-arr/lint189-First-Missing-Positive.md)

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
	
	


