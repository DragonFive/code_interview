---
title: 80-remove-duplicates-from-sorted-array-ii
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem 
[80/remove-duplicates-from-sorted-array-ii](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)

## similiar problem 

[lint 101](http://www.lintcode.com/en/problem/remove-duplicates-from-sorted-array-ii/)


# solution

## tow point 

```cpp
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() <= 2)
            return nums.size();
        int left = 0, right = 0, last = -1, count = 0;
        last = nums[0];count = 1; left = 1; right = 1;
        const int nums_size = nums.size();
        for ( ; right < nums_size; right++)
        {
            if (nums[right] !=  last)
                count = 0;
            if (nums[right] !=  last || count < 2)
            {
                nums[left] = nums[right];
                last = nums[left];left++ ;count++;
            }
            else
                count++;
        }
        return left;
        
    }
```