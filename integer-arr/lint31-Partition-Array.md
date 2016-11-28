---
title: lint31-Partition-Array
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# source
[lintcode 31 Partition Array](http://www.lintcode.com/en/problem/partition-array/)


# solution

## two pointer
```cpp
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        // 判断是否为空;
        if (nums.empty())
            return 0;
        //使用快速排序的方法;
        int start = 0, end = nums.size() - 1;
        while (start < end)
        {
            if (nums[start] < k)
            {
                start++;
                continue;
            }
            if (nums[end] >= k)
            {
                end--;
                continue;
            }
            //开始交换了;
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++; end--;
        }
        if (nums[end] < k)
            return end + 1;
        return end;
    }
```

## 夹层法

```cpp
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        // 判断是否为空;
        if (nums.empty())
            return 0;
        // 使用隔间法;
        int lower = 0, upper = 0;
        while (upper < nums.size())
        {
            if (nums[upper] >= k)
                upper++;
            else
            {
                int temp = nums[upper];
                nums[upper] = nums[lower];
                nums[lower] = temp;
                lower++; upper++; 
            }
        }
        return lower;
    }
```