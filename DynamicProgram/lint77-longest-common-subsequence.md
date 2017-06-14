---
title: lint77-longest-common-subsequence
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem

[lint77-longest-common-subsequence](http://www.lintcode.com/en/problem/longest-common-subsequence/)

# solution

```cpp
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if (A.empty() || B.empty())
            return 0;
        vector<vector<int> > nums(B.size()+1, vector<int>(A.size() + 1,0));
        for (int i = 0; i < B.size(); i++)
            for (int j = 0; j < A.size(); j++)
                if (A[j] == B[i])
                    nums[i+1][j+1] = nums[i][j] + 1;
                else
                    nums[i+1][j+1] = max(nums[i+1][j], nums[i][j+1]);//使用std空间里的max函数
        return nums[B.size()][A.size()];
    }
```