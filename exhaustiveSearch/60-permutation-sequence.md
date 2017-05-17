---
title: 60-permutation-sequence
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[60-permutation-sequence](https://leetcode.com/problems/permutation-sequence/#/description)

## similiar problem

[]()

[]()

# solution

```
    string getPermutation(int n, int k) {
        //首先缓存所有的结果
        vector<int> factorial = vector<int>(n+1, 1);
        for (int i = 1; i < n+1; i++)
            factorial[i] = factorial[i-1]*i;
        
        vector<int> perm;
        vector<int> nums;
        for (int i = 1; i < n+1; i++)
            nums.push_back(i);
        //然后循环计算每一个位置上的数值
        for (int i = 0; i < n; i++)
        {
            int rank = (k - 1) / factorial[n -i - 1];
            k = (k - 1) % factorial[n - i - 1] + 1;
            //找到第rank个元素;
            perm.push_back(nums[rank]);
            nums.erase(nums.begin() + rank);
        }
        stringstream result;
        copy(perm.begin(), perm.end(), ostream_iterator<int>(result,""));
        return result.str();
    }
```
## code analysis


# reference

[Permutation Sequence 解题报告](http://blog.sina.com.cn/s/blog_eb52001d0102v1ss.html)

[stackoverflow-how-to-transform-a-vectorint-into-a-string](http://stackoverflow.com/questions/2518979/how-to-transform-a-vectorint-into-a-string)
