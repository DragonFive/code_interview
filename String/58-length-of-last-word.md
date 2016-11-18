---
title: 58-length-of-last-word
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---



# source

[58. Length of Last Word](https://leetcode.com/problems/length-of-last-word/)

## similiar problem in lintcode
[422 Length of Last Word](http://www.lintcode.com/en/problem/length-of-last-word/)

# solution

```cpp
    int lengthOfLastWord(string& s) {
        // Write your code here
        if (s.empty())
            return 0;
        int len = s.length();
        vector<int> numWord(len + 1, 0);
        for (int i = 0; i < len; i++)
            if (isalpha(s[i]))
                numWord[i + 1] = numWord[i] + 1;
        for (int j = len; j > 0; j--)
            if (numWord[j] != 0)
                return numWord[j];
        return 0;
        
    }
```