---
title: 139-word-break
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[139-word-break](https://leetcode.com/problems/word-break/#/description)

# solution

```cpp
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        //自底向上;
        vector<bool> status(false, len);// 表明从开头到当前的位置的字符串能够被字典表示
        for (int i = 1; i <= len; i++)//以长度进行遍历
        {
            string str = s.substr(0, i);
            if (find(wordDict.begin(), wordDict.end(), str) != wordDict.end())
                status[i-1] = true;
            else // 如果没有就从中间拆分;遍历每个可索引字符串的后缀
                for (int j = i -2; j >= 0; j--)
                    if (status[j] == true && find(wordDict.begin(), wordDict.end(), s.substr(j + 1,i -j -1))!=wordDict.end() )
                    {
                        status[i-1] = true;
                        break;
                    }
        }
        return status[len - 1];
    }
```