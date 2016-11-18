---
title: 38-countAndSay
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---
# source
[38. Count and Say](https://leetcode.com/problems/count-and-say/)

## similiar problem in lintcode
[420 Count and Say](http://www.lintcode.com/en/problem/count-and-say/)

# solution

```cpp
    string countAndSay(int n) {
        // Write your code here
        if (n == 1)
            return "1";
        string preN = countAndSay(n - 1);
        vector<int>  chNums;
        vector<char> charPr;
        int len = preN.length();
        for (int i = 0; i < len; i++)
        {
            if (charPr.empty() || charPr[charPr.size() - 1] != preN[i])
            {
                charPr.push_back(preN[i]);
                chNums.push_back(0);
            }
            chNums[chNums.size() - 1] ++;
        }
        string retStr;
        int lenNums = chNums.size();
        for(int i = 0; i < lenNums; i++)
        {
            retStr+=chNums[i] + '0' - 0;
            retStr+=charPr[i];
        }
        return retStr;
    }
```