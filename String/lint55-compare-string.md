---
title: lintcode-compare-string
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# 题目来源 
[Compare Strings](http://www.lintcode.com/en/problem/compare-strings/#)
# 哈希表法
## 使用数组
需要注意的是数组的大小，以及各个元素的转换关系
```cpp
    bool compareStrings(string s, string t) {
        // write your code here
        
        const int charNum = 26;
        int charContain[charNum] = {0};
        for(int i = 0;i < s.length();i++)
            charContain[s[i] - 'A']++;
        for(int i = 0;i < t.length();i++)
            charContain[t[i] - 'A']--;
        for(int i = 0;i < t.length();i++)
            if(charContain[t[i] - 'A'] < 0)
                return false;
        return true;
    }
```
