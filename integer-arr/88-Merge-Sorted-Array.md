---
title: 88-Merge-Sorted-Array
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem

[88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

## similiar problem 

[lint6 merge-sorted-array](http://www.lintcode.com/en/problem/merge-sorted-array/)

# solution

```cpp
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums1.empty() || nums2.empty())
            return;
        int j = m - 1 , k = n - 1, i = m + n - 1;
        for (; i >= 0; i--)
        {
            if (j < 0 || k < 0 )
                break;
            if (nums1[j] > nums2[k])
                nums1[i] = nums1[j--];
            else
                nums1[i] = nums2[k--];
        }
        while(k>=0)
        {
            nums1[i--] = nums2[k--];
        }
    }
```