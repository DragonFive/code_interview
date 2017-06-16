---
title: lint42-maximum-subarray-ii
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lint42-maximum-subarray-ii](http://www.lintcode.com/en/problem/maximum-subarray-ii/)

# solution

## solution1 动态规划
```cpp
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        //先找前半部分的最大值，再找后半部分的最大值;
        if (nums.empty())
            return 0;
        vector<int> maxsumf(nums.size(), 0);
        vector<int> maxsumb(nums.size(), 0);
        int sum = 0, minSum = 0, maxsum = INT_MIN;//maxSum算的是maxsumf的最大值;
        for (int i = 0; i < nums.size() ; i++)
        {
            minSum = min(minSum, sum);
            sum += nums[i];
            maxsum = max(maxsum, sum - minSum);
            maxsumf[i] = maxsum;
        }
        sum = 0;minSum = 0;maxsum = INT_MIN;
        for (int i = nums.size()-1; i>=0;i--)
        {
            minSum = min(minSum, sum);
            sum+=nums[i];
            maxsum = max(maxsum, sum - minSum);
            maxsumb[i] = maxsum;
        }
        //下面开始计算两者的和;
        maxsum = INT_MIN;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxsum = max(maxsum, maxsumf[i] + maxsumb[i+1]);
        }
        return maxsum;
    }
```

## solution2. 贪心法
```cpp

```

# reference
[九章算法](https://www.jiuzhang.com/solution/maximum-subarray-ii/)