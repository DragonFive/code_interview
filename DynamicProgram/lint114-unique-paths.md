---
title: lint114-unique-paths
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lint114-unique-paths](http://www.lintcode.com/en/problem/unique-paths/)

# solution
```cpp
    int uniquePaths(int m, int n) {
        // wirte your code here
        if (m == 0 || n == 0 )
            return 0;
        if (m ==1 || n==1)
            return 1;
        vector<int> nums(n, 1);
        for (int i = 1;  i  < m; i++)
            for (int j = 1;j < n; j++)
                nums[j] += nums[j-1];        
        return nums[n-1];
    }
```

