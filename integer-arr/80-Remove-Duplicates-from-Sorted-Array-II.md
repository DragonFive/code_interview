---
title: 80-Remove-Duplicates-from-Sorted-Array-II
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem

[80. Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)

# solution 

```cpp
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        const int nums_size = nums.size();
        if (nums_size < 3)
            return nums_size;
        int j = 1;
        bool equaled = false;
        for (int i = 1; i< nums_size; i++)
        {
            if (nums[i] == nums[i - 1] && equaled)// 已经不是第一次相等了;
                continue;
            if (nums[i] == nums[i - 1])
                equaled = true;
            else
                equaled = false;
            nums[j] = nums[i];
            j++;
        }
        return j;
    }
```