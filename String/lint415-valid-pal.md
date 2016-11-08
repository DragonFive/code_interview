---
title: lint415-valid-pal
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---
# 题目来源

[415 valid palindrome](http://www.lintcode.com/en/problem/valid-palindrome/)


# 解法

## 首尾递进

```cpp
    bool isPalindrome(string& s) {
        // Write your code here
        int len = s.length();
        int start = 0, end = len - 1;
        while (end >= start)
        {
            while (!(isdigit(s[start]) || isalpha(s[start]) ) ) 
                start++;
            while (!(isdigit(s[end]) || isalpha(s[end]) ) )
                end--;
            if (end >= start && (s[end] - s[start]) % ('A' - 'a') != 0) 
                return false;
            start++;
		    end--;
        }
        return true;
    }
```