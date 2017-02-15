---
title: 215-kth-largest-element-in-an-array
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem

[215-kth-largest-element-in-an-array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

## similiar problem

 
[/lint80-median](https://github.com/DragonFive/Leetcode/blob/master/integer-arr/lint80-median.md)

[lint5 (5) Kth Largest Element](http://www.lintcode.com/en/problem/kth-largest-element/)

# solution

## 局部快排法

```cpp
    int findKthLargest(vector<int>& nums, int k) {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int res = getFirstPos(nums, i ,j);
            if (res == k) break;
            if (res <  k)
                i = res;
            else
                j = res - 2;
        }
        return nums[k - 1];
    }
    int getFirstPos(vector<int>& nums, int l, int r)
    {
        if (l == r)
            return l + 1;
        int temp = nums[l];
        int i = l, j = r;
        while (i <= j )
        {
            while (nums[i] >= temp  && i < r) i++;
            while (nums[j] < temp && j > 0) j--;
            if (i <= j)
            {
                int t = nums[i];
                nums[i++] = nums[j];
                nums[j--] = t;
            }
        }
        int t = nums[i-1];
        nums[i-1] = temp;
        nums[l] = t;
        return i;
    }
```

## stl的方法 nth_element

···cpp
    int kthLargestElement(int k, vector<int> nums) {
        nth_element(nums.begin(), nums.begin() + k ,nums.end());
        return nums[nums.size() - k];
    }
```


# 学习资料

[寻找第K大的数的方法总结](http://www.cnblogs.com/zhjp11/archive/2010/02/26/1674227.html)