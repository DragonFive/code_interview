---
title: lint212-Space-Replacement
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# 题目来源

[lintcode 212-Space-Replacement](http://www.lintcode.com/en/problem/space-replacement/)

水题

# 解法

```cpp
    int replaceBlank(char string[], int length) {
        // Write your code here
        // 先计算空格的个数
        int newLength = length;
        for (int i = 0; i < length; i++)
            if (string[i] == ' ')
                newLength += 2;
        //然后从后往前改变字符串
        int i = length - 1, j = newLength - 1;
        while (j > i)
        {
            if (string[i] == ' ')
            {
                string[j] = '0';
                string[j-1] = '2';
                string[j-2] = '%';
                j -= 3; 
            }
            else
            {
                string[j] = string[i];
                j--;
            }
            i--;
        }
        return newLength;
    }
```