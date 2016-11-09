---
title: lint200-Longest-Palindromic-Substring
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# 题目来源 
[lint200-Longest-Palindromic-Substring](http://www.lintcode.com/en/problem/longest-palindromic-substring/)
## 相似题目

[leetcode 5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
# 解法 

## 寻找最长公共字串（错误的做法） 

时间复杂度为O(n^2)
```cpp
    string longestPalindrome(string& s) {
        // Write your code here
        if (s.empty())
            return s;
        string t = s;
        std::reverse(t.begin(), t.end());
        int len = s.length();
        vector<vector<int> > lenVec =  vector<vector<int> >(len + 1, vector<int>(len + 1, 0));
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                if (s[i] == t[j])
                    lenVec[i + 1][j + 1] = lenVec[i][j] + 1;
        int maxLen = 0, endIdx = 0;
        for (int i = 0; i <= len; i++)
            for (int j = 0; j <= len; j++)
                if (lenVec[i][j] > maxLen)
                {
                    maxLen = lenVec[i][j];
                    endIdx = i - 1;
                }    
        return s.substr(endIdx - maxLen + 1, maxLen);                    
    }
```
**注意** 上面的做法是错误的 
[Longest Palindromic Substring Part I](http://articles.leetcode.com/longest-palindromic-substring-part-i)
里面有解释
比如 S = “abacdfgdcaba”, 则它翻转之后为S’ = “abacdgfdcaba”  计算结果为 “abacd”，显然这个是最长的子序列
## 两端拓展法
这里认为遍历到的一个位置是回文字的中心，然后去找它的边界。这里的子问题是以该位置为中心的回文数的长度。
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





