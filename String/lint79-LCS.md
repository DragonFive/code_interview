---
title: lint79-LCS 
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# 题目来源 
[Longest Common Substring](http://www.lintcode.com/en/problem/longest-common-substring/#)

# 解法

## 动态规划
### 下面是节省空间但逻辑比较复杂的代码
动态规划注意初始化，和状态的转移; 时间复杂度$O(n^2)$
```cpp
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int subIndexA, subIndexB, coLen, i = 0;
        //先初始化各个元素
        for (; i < B.length(); i++)
        {
            if (A.find(B[i]) != string::npos)
            {
                subIndexA = A.find(B[i]);
                subIndexB = i;
                coLen = 1;
                break;
            }
        }
        if (i == B.length())
            return 0;
        //i表示待考察的B的下标;
        for (i = subIndexB + 1; i < B.length(); i++)
        {
            //使用动态规划的办法B的长度不断地增长;
            //如果当前的下标正好在之前的后一个 则判断是否相等
            if ( subIndexB + coLen == i && A[subIndexA + coLen] == B[i])
                coLen++;
            else
            {
                //就看从i往前看,是否有长度为coLen的其它字串呢;
                int tempIndex = A.find(B.substr(i - coLen, coLen + 1), 0);
                if ( tempIndex != string::npos)
                {
                    subIndexA = tempIndex;
                    coLen++;
                    subIndexB = i - coLen + 1;
                }
                else
                {
                    tempIndex = A.find(B.substr(i - coLen + 1, coLen), 0);
                    if ( tempIndex != string::npos)
                    {
                        subIndexA = tempIndex;
                        subIndexB = i - coLen + 1;
                    }
                }
            }
        }
        return coLen;
    }
```

### 下面是正统的动态规划的代码 

二维数组表示的是以i,j结尾的且其字符相等的字串LCS，如果不相等则为0，不做修改，很是方便啊
注意这里面二维数组直接使用vector的vector很是方便呢

```cpp
    int longestCommonSubstring(string &A, string &B) {
        if (A.empty() || B.empty())
            return 0;
        int lenA = A.length();
        int lenB = B.length();
        //下面的动态二维数组保存的是以i,j结尾的子串的长度;
        vector<vector<int>> lcsVec(lenA + 1, vector<int>(lenB + 1, 0));
        for (int i = 0; i < lenA; i++)
        {
            for (int j = 0; j < lenB; j++)
            {
                //把i,j的结果保存在i+1,j+1里面便于初始化;
                if (B[j] == A[i] )
                    lcsVec[i + 1][j + 1] = lcsVec[i][j] + 1;
            }
        }
        //下面找到最大的lcs;
        int maxLcs = 0;
        for (int i = 0; i < lenA + 1; i++)
            for (int j = 0; j < lenB + 1; j++)
                if (lcsVec[i][j] > maxLcs)
                    maxLcs =  lcsVec[i][j];
        return maxLcs;
    }
```