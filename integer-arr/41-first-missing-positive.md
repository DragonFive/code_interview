---
title: 41-first-missing-positive
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
其实这个答案问题还是蛮多的，比如空间复杂度占得多，题目的挑战性要求是时间复杂度O(n)，空间复杂度是常数
	
## bucket sort 

下面的方法用的是通排序的变种
	
设想我们对给定数组使用桶排序的思想排序，第一个桶放1，第二个桶放2，如果找不到相应的数，则相应的桶的值不变(可能为负值，也可能为其他值)。+

那么怎么才能做到原地排序呢？即若 A[i] = x, 则将 x 放到它该去的地方 - A[x - 1] = x, 同时将原来 A[x - 1地方的值交换给 A[i].
排好序后遍历桶，如果不满足 f[i] = i + 1, 那么警察叔叔就是它了！如果都满足条件怎么办？那就返回给定数组大小再加1呗。



# reference

[LeetCode: First Missing Positive 解题报告](http://www.cnblogs.com/yuzhangcmu/p/4200096.html)
