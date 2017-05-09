---
title: 31-next-permutation
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem

[31-next-permutation](https://leetcode.com/problems/next-permutation/#/description)
# solution

```
    void nextPermutation(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1)
            return;
        //找到最长降序后缀;
        int i = nums.size() - 2;
        for (; i >=0; i--)
            if (nums[i] < nums[i+1])
                break;
        if (i == -1)
        {
            //重新排列，然后继续;
            sort(nums.begin(), nums.end());
            return;
        }
        //找到第一个比哨兵大的元素;
        int j = nums.size() - 1;
        for (; j > i; j--)
            if (nums[j] > nums[i])
                break;
        //交换
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        //reverse;
        reverse(nums.begin() + i +1, nums.end());
        
        
    }
```

# reference