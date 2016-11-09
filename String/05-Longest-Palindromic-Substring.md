---
title: 05-Longest-Palindromic-Substring
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# 解法
```cpp
    string longestPalindrome(string& s) 
    {
        // Write your code here
        if (s.empty())
            return s;
        string res;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            string temp;
            temp = findPalindrome(s, i, i);
            if (temp.size() > res.size())res = temp;
            temp = findPalindrome(s, i, i+1);
            if (temp.size() > res.size())res = temp;
        }
        return res;
    }
    string findPalindrome(string& s, int m, int n)
    {
        while (m >= 0 && n < s.size() && s[m] == s[n])
        {
            m--;
            n++;
        }
        return s.substr(m + 1, n - m - 1);
    }
```