---
title: lint116-jump-game
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lint116-jump-game](http://www.lintcode.com/en/problem/jump-game/)

# solution

```cpp
    bool canJump(vector<int> A) {
        // write you code here
        if (A[0] == 0 && A.size() > 1)
            return false;
        int maxPos = A[0];
        for (int i = 1 ; i < A.size();)
        {
            int maxPosNow = -1;
            //统计这一段中的最大值;
            for (int j = i; j <= maxPos; j++)
                if (j + A[j] > maxPosNow)
                    maxPosNow = j+A[j];
            i = maxPos + 1;
            if (maxPosNow <= maxPos && maxPosNow < A.size()-1)
                return false;
            maxPos = maxPosNow;
            if (maxPos >= A.size() - 1)
                return true;
            
        }
        return true;
    }
```