---
title: lint117-jump-game-ii
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lint117-jump-game-ii](http://www.lintcode.com/en/problem/jump-game-ii/)
# solution
```cpp
    int jump(vector<int> A) {
        // wirte your code here
        if (A.empty())
            return 0;
        int lastPos = 1;
        int pos = 0;
        int k = 1;
        for (int i = 0; i < A.size();)
        {
            if (i+A[i] >= A.size())
                break;
            //从当前的pos开始到下一个pos;
            // int j = i+1;
            // for (; j <= i+A[i]; j++)
            //     if (j + A[j] > pos)
            //         pos = j + A[j];
            // //开始交换
            // if (pos <= i+A[i])
            //     return -1;//不能到最后
            i = i+A[i] + 1;
            k++;
        }
        return k;
    }
```