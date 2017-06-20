---
title: lint397-longest-increasing-continuous-subsequence
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lint397-longest-increasing-continuous-subsequence](http://www.lintcode.com/en/problem/longest-increasing-continuous-subsequence/)
# solution
```cpp
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        if (A.empty())  
            return 0;
        // Write your code here
        int left = 1, maxleft = 1, right = 1, maxright = 1;
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] >= A[i-1])
            {
                left+=1;
                right = 1;
            }
            else
            {
                left = 1;
                right += 1;
            }
            maxleft = max(maxleft, left);
            maxright = max(maxright, right);
        }
        return max(maxleft,maxright);
    }
```