---
title: 300-longest-increasing-subsequence
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[300-longest-increasing-subsequence](https://leetcode.com/problems/longest-increasing-subsequence/#/description)
# solution
```cpp
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty() || nums.size() == 0)
            return 0;
        vector<int> lens( nums.size(),0 );//标记的是以这个位置结束的自增序列的长度;
        lens[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            //从0开始找比它大的位置;
            int bigger = 0;
            for (int j = 0 ; j < i; j ++)
                if (nums[i] > nums[j] && lens[j] > bigger)
                    bigger = lens[j];
            lens[i] = bigger + 1;
        }
        //找到lens数组中的最大值;
        int maxLen = 0;
        for (int i = 0; i < lens.size(); i++)
            if (maxLen < lens[i])
                maxLen = lens[i];
        return maxLen;
    }
```