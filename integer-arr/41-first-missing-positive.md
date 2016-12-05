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

### 理解 
下面的方法用的是通排序的变种
	
设想我们对给定数组使用桶排序的思想排序，第一个桶放1，第二个桶放2，如果找不到相应的数，则相应的桶的值不变(可能为负值，也可能为其他值)。+

那么怎么才能做到原地排序呢？即若 A[i] = x, 则将 x 放到它该去的地方 - A[x - 1] = x, 同时将原来 A[x - 1地方的值交换给 A[i].
排好序后遍历桶，如果不满足 f[i] = i + 1, 那么警察叔叔就是它了！如果都满足条件怎么办？那就返回给定数组大小再加1呗。

### 代码

```cpp
    int firstMissingPositive(vector<int> A) {
        // write your code here
        const int size = A.size();
        for (int i = 0; i < size; i++)
        {
            while (A[i] <= size && A[i] > 0 && A[i] != A[A[i] - 1] && A[i] != i + 1)
            {
                int temp = A[A[i] - 1];
                A[A[i] - 1] = A[i];
                A[i] = temp;
            }
        }
        //下面开始遍历这些内容了;
        for (int i = 0; i < size; i++)
            if (A[i] != i + 1)
                return i + 1;
        return size + 1;
    }
```

### 分析

核心代码为那几行交换，但是要很好地处理各种边界条件则要下一番功夫了，要能正常的交换，需满足以下几个条件：
A[i] 为正数，负数和零都无法在桶中找到生存空间...
A[i] \leq size 当前索引处的值不能比原数组容量大，大了的话也没用啊，肯定不是缺的第一个正数。
A[i] != i + 1, 都满足条件了还交换个毛线，交换也是自身的值。
A[i] != A[A[i] - 1], 避免欲交换的值和自身相同，否则有重复值时会产生死循环。
如果满足以上四个条件就可以愉快地交换彼此了，使用while循环处理，此时i并不自增，直到将所有满足条件的索引处理完。
注意交换的写法，若写成
int temp = A[i];
A[i] = A[A[i] - 1];
A[A[i] - 1] = temp;
这又是满满的 bug :( 因为在第三行中A[i]已不再是之前的值，第二行赋值时已经改变，故源码中的写法比较安全。
最后遍历桶排序后的数组，若在数组大小范围内找到不满足条件的解，直接返回，否则就意味着原数组给的元素都是从1开始的连续正整数，返回数组大小加1即可。


# reference

[LeetCode: First Missing Positive 解题报告](http://www.cnblogs.com/yuzhangcmu/p/4200096.html)

[First Missing Positive](https://algorithm.yuanbin.me/zh-hans/integer_array/first_missing_positive.html)
