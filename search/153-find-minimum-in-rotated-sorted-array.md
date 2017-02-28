---
title: 153-find-minimum-in-rotated-sorted-array
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem
[153-find-minimum-in-rotated-sorted-array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/?tab=Description)
## similiar problem

[33-search-in-rotated-sorted-array.md](https://github.com/DragonFive/Leetcode/blob/master/search/33-search-in-rotated-sorted-array.md)

[81-search-in-rotated-sorted-array-ii.md](https://github.com/DragonFive/Leetcode/blob/master/search/81-search-in-rotated-sorted-array-ii.md)

# solution
起点比较法
```cpp
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        if (nums.size() == 1 || nums[0] < nums[j])
            return nums[0];
        while ( i + 1 < j )
        {
            int k = i + (j - i) / 2;
            if (nums[i] < nums[k])
            {//说明左边是有序序列;最小值在右边;
                i = k;
            }
            else
                j = k;
        }
        return nums[j];
    }
```