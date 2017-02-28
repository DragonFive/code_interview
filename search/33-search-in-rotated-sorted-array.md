---
title: 33-search-in-rotated-sorted-array
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem

[33-search-in-rotated-sorted-array](https://leetcode.com/problems/search-in-rotated-sorted-array/?tab=Description)
## similiar problem

[lint62 Search in Rotated Sorted Array](http://www.lintcode.com/en/problem/search-in-rotated-sorted-array/)

# solution

```cpp
    int search(vector<int>& nums, int target) {
        //先找到中间点;
        if (nums.empty())
            return -1;
        int i = 0, j = nums.size() - 1;
        if ( nums[i] > nums[j])
        {
            while ( i + 1 < j)
            {
                int k = i + (j - i) / 2;
                if (nums[k] > nums[0])
                    i = k;
                else
                    j = k;
            }
        }
        else
            i = j;
        if (target >= nums[0])//左边
        {
            return binSearch(nums, 0, i, target);
        }
        else//右边
        {
            return binSearch(nums, j, nums.size()-1, target);
        }
        
    }
    int binSearch(vector<int>& nums, int start, int end, int target)
    {
        if (start == end && nums[start] != target)
            return -1;
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            return binSearch(nums, mid + 1, end, target);
        else
            return binSearch(nums, start, mid, target);
    }
```