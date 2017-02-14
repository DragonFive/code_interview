---
title: lint373-Partition-Array-by-Odd-and-Even
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# resource

[lint 373 Partition Array by Odd and Even](http://www.lintcode.com/en/problem/partition-array-by-odd-and-even/)

# answer

```cpp
    void partitionArray(vector<int> &nums) {
        // write your code here
        if (nums.empty() || nums.size() == 1)
            return;
        const int numsSize = nums.size();
        int i = 0, j = numsSize - 1;
        while (i < j)
        {
            while ( nums[i] % 2 == 1 && i < numsSize) i++;
            while ( nums[j] % 2 == 0 && j > 0) j--;
            if (i < j)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++; j--;
            }
        }
        return;
    }
```