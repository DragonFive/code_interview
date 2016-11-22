---
title: lint39-Recover-Rotated-Sorted-Array
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# source
[lintcode 39 Recover Rotated Sorted Array](http://www.lintcode.com/en/problem/recover-rotated-sorted-array/)
## similiar problem 

[lintcode 8. rotate string](http://www.lintcode.com/en/problem/rotate-string/)


# solution
三步翻转法
```cpp
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        if (nums.empty())
            return;
        //先找到旋转的位置;
        int i = 0;
        for (; i < nums.size(); i++)
            if (nums[i] > nums[i + 1])
                break;
        if (i == nums.size())
            return;
        reverseArray(nums, 0, i);
        reverseArray(nums, i + 1, nums.size() - 1);
        reverseArray(nums, 0, nums.size() - 1);
    }
    void reverseArray(vector<int> &nums, int begin, int end)
    {
        while (begin < end)
        {
            int temp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = temp;
            begin++;end--;
        }
    }
```
