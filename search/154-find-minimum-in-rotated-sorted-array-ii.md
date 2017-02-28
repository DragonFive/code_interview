---
title: 154-find-minimum-in-rotated-sorted-array-ii
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem

[154-find-minimum-in-rotated-sorted-array-ii](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/?tab=Description)

## similiar problem

[33-search-in-rotated-sorted-array.md](https://github.com/DragonFive/Leetcode/blob/master/search/33-search-in-rotated-sorted-array.md)

[81-search-in-rotated-sorted-array-ii.md](https://github.com/DragonFive/Leetcode/blob/master/search/81-search-in-rotated-sorted-array-ii.md)

# solution

```cpp
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while ( i + 1 < j )
        {
            int k = i + (j - i) / 2;
            if (nums[i] < nums[k])
            {//说明左边是有序序列;最小值在右边;或者本来就是有序序列
                if (nums[i] < nums[j])
                    return nums[i];
                else
                    i = k;
            }
            else if (nums[i] > nums[k])
                j = k;
            else
                i++;
        }
        if (nums[i] < nums[j])
            return nums[i];
        return nums[j];
    }
```