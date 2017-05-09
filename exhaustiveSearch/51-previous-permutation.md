---
title: lint-51-previous-permutation
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[51-previous-permutation](http://www.lintcode.com/en/problem/previous-permutation/)

# solution

```
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        vector<int> res = nums;
        if (nums.empty() || nums.size() == 1)
            return res;
        
        int i = res.size() - 2;
        for (; i >= 0; i--)
            if (res[i] > res[i+1])
                break;
        if (i == -1)
        {
            reverse(res.begin(), res.end());
            return res;
        }
        //找到置换元素;
        int j = res.size() -1 ;
        for (; j > i; j--)
            if (res[j] < res[i])
                break;
        //jiaohuan
        int temp = res[i];
        res[i] = res[j];
        res[j] = temp;
        
        //reverse;
        reverse(res.begin()+i+1, res.end());
        return res;
    }
```

# reference
