---
title: 2017-3-9-lint181-flip-bits
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem 

[lint181-flip-bits](http://www.lintcode.com/en/problem/flip-bits/)
# solution

```cpp
    int bitSwapRequired(int a, int b) {
        // write your code here
        int c = a ^ b;
        int sum = 0;
        for (int i = 0 ; i < 8 * sizeof(int); i++)
        {
            sum += ( c >> i ) & 1;
        }
        return sum;
    }
```

