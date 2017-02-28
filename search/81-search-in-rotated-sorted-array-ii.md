---
title: 81-search-in-rotated-sorted-array-ii
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[81search-in-rotated-sorted-array-ii](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/?tab=Description)

## similiar problem 

[63search-in-rotated-sorted-array-ii/](http://www.lintcode.com/en/problem/search-in-rotated-sorted-array-ii/)

# solution

```cpp
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;
        int i = 0, j = nums.size() - 1;
        while ( i + 1 < j)
        {
            int k = i + (j - i) / 2;
            if (nums[k] == target)
                return true;
            if (nums[i] < nums[k])
            {//左边是有序序列
                if (nums[k] >= target && nums[i] <= target)//落在有序范围内
                {
                    j = k;
                }
                else
                {
                    i = k;
                }
            }
            else if (nums[i] > nums[k])
            {//右边是有序序列;
                if (nums[k] <= target && nums[j] >= target)//落在有序范围内
                    i = k;
                else//可能更大也可能更小
                    j = k;
            }
            else
                i++;
        }
        if (nums[i] == target || nums[j] == target)
            return true;
        return false;
	}
```

# reference

[leetcode 题解](https://algorithm.yuanbin.me/zh-hans/binary_search/search_in_rotated_sorted_array_ii.html)