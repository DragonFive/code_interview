---
title: 131-palindrome-partitioning 
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[131-palindrome-partitioning](https://leetcode.com/problems/palindrome-partitioning/#/description)

# solution
```
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if (s.empty())
            return result;
        if (s.size() == 1)
        {
            vector<string> vec;
            vec.push_back(s);
            result.push_back(vec);
            return result;
        }
        //下面开始分端;
        for (int i = 1; i <= s.size(); i++)
        {
            if (!isPalindrome(s.substr(0, i)) )
                continue;
            vector<string> vec;
            vec.push_back(s.substr(0, i));
            if (i == s.size())
            {
                result.push_back(vec);
                break;
            }
            vector<vector<string>> rightStr = partition(s.substr(i, s.size()-i));
            for (int j = 0; j < rightStr.size(); j++)
            {
                //合并当前的vec,与其中的每一个vector;
                vector<string> vec2;
                vec2.insert(vec2.end(), vec.begin(),vec.end());
                vec2.insert(vec2.end(), rightStr[j].begin(), rightStr[j].end());
                result.push_back(vec2);
            }
        }
        return result;
    }
    bool isPalindrome(string s)
    {
        for (int i =0; i < s.size()/2 + 1; i++)
        {
            if (s[i] != s[s.size() - i - 1])
                return false;
        }
        return true;
    }
```

# reference
