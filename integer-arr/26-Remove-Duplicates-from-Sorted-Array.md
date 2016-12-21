---
title: 26-Remove-Duplicates-from-Sorted-Array 
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem 

[26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

# solution 

## 过滤法
```cpp
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty() )
            return 0;
        const int nums_size = nums.size();
        int replace = -1;
        for (int i = 1; i < nums_size; i++)
            if (nums[i] == nums[i - 1])
            {
                replace = i;
                break;
            }
        if (replace == -1)
            return nums_size;
        int j = replace + 1;
        while (j < nums_size && nums[j] == nums[j - 1])
            j++;
        for (; j < nums_size; )
        {
            nums[replace] = nums[j];
            replace++;
            j++;
            while (j < nums_size && nums[j] == nums[j - 1])
                j++;
        }
        return replace;
    }
```