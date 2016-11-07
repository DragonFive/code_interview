---
title: lint53-reverseWord
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# 题目来源

[53 Reverse Words in a String](http://www.lintcode.com/en/problem/reverse-words-in-a-string/#)


# 解法

```cpp
    string reverseWords(string s) {
        // write your code here
        if (s.empty() )
            return s;
        vector<string> strVec;
        stringstream strStr(s);
        string temp, result;
        while(strStr>>temp)
            strVec.push_back(temp);
        if (strVec.size() < 2)
            return s;
        for (int i = strVec.size() - 1; i > 0; i--)
        {
            result += strVec[i] + " ";
        }
        result += strVec[0];
        return result;
    }
```
