---
title: 96-Unique-Binary-Search-Trees 
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem
[96-Unique-Binary-Search-Trees](https://leetcode.com/problems/unique-binary-search-trees/#/description)

# solution

```cpp
    int numTrees(int n) {
        
        if (n <=2)
            return n;
        int sum = 0;
        sum = 2*numTrees(n-1);
        for (int i = 1; i < n - 1; i++)
        {
            sum = sum + numTrees(i) * numTrees(n -1 - i);
        }
        return sum;

```

# upgrade
这其实是一个卡特兰数，1,1,2,5,14,42 
`!$ \frac{1}{n+1}C_{n!}^{(2n)!} $`

其实应该使用正规的正态规划来做，使用状态转移方程。
`!$ count[n] = \frac{4n-2}{n+1}*count[n-1] $`

```cpp
    int numTrees(int n) {
        long long nums[n+1];
        memset(nums,0,sizeof(int)*(n+1));
        nums[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            nums[i] = nums[i-1]*(4*i-2)/(i+1);
        }
        return nums[n];
    }
```

使用这种时空复杂度都为O(n)的方法的前提是要知道它是卡特兰数。

如果不知道还是乖乖地使用一般的方法吧。


