---
title: lint50-Product-Array-Exclude-itself
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# source

[lintcode 50 Product of Array Exclude Itself]()
# solution

## rude solution

```cpp
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> result;
        if (nums.empty() || nums.size() < 2)
        {
            result.push_back(1);
            return result;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            long long product = 1;
            for (int j = 0; j < nums.size(); j++)
                if (j != i)
                    product *= nums[j];
            result.push_back(product);
        }
        return result;
    }
```


## divide and conquer
左右分治法，其实应该算是递推法

```cpp
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        const int numsSize = nums.size();
        vector<long long> result(numsSize, 1); //先分配空间;
        if (nums.empty() || numsSize == 1)
            return result;
        vector<long long> left(numsSize, 1);
        vector<long long> right(numsSize, 1);
        //开始计算左边;
        for (int i = 1; i < numsSize; i++)
            left[i] = left[i - 1] * nums[i - 1];
        //再计算右边;
        for (int i = numsSize - 2; i >= 0; i--)
            right[i] = right[i + 1] * nums[i + 1];
        //然后把两者合并;
        for (int i = 0; i < numsSize; i++)
            result[i] = left[i] * right[i];
        return result;
    }
```
