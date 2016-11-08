---
title: 125-valid-pal
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# 题目来源

[125 valid palindrome](https://leetcode.com/problems/valid-palindrome/)

## lintcode相似题目 



[415 valid palindrome](http://www.lintcode.com/en/problem/valid-palindrome/)

# 解法

```cpp
    bool isPalindrome(string s) {
        int start = 0, end = s.length() - 1;
        while (end > start)
        {
            if (!isalnum(s[start]) )
            {
                start++;
                continue;
            }
            if (!isalnum(s[end]) )
            {
                end--;
                continue;
            }
            if( tolower(s[start]) != tolower(s[end]) )
                return false;
            start++;
            end--;
        }
        return true;
    }
```
