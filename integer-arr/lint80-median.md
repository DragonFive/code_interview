---
title: lint80-median
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---
# source

[(80) Median](http://www.lintcode.com/en/problem/median/#)

# solution

```cpp
    int median(vector<int> &nums) {
        // write your code here
        const int numsSize = nums.size();
        int posInd = numsSize % 2 == 0 ? (numsSize - 1) / 2 : numsSize / 2;
        int left = 0, right = numsSize - 1;
        while (true)
        {
            int pos = getFirstPos(nums, left, right);
            if (pos == posInd)
                return nums[pos];
            if (pos > posInd)
                right = pos - 1;
            else
                left = pos + 1;
        }
    }
    int getFirstPos(vector<int> &nums, int begin, int endp)
    {
        if (begin == endp)  
            return begin;
        int start = begin, end = endp;
        int temp = nums[start];
        while(start <= end)
        {
            while (nums[start] <= temp && start <= endp)
                start++;
            while (nums[end] > temp && end >= begin)
                end--;
            if (start <= end)
            {
                int t = nums[start];
                nums[start++] = nums[end];
                nums[end--] = t;
            }
        }
        nums[begin] = nums[start - 1];
        nums[start - 1] = temp;
        return start - 1;
    }
```