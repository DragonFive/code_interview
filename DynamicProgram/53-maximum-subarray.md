---
title: 53-maximum-subarray
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[53-maximum-subarray](https://leetcode.com/problems/maximum-subarray/#/description)

# solution
## 使用辅助空间+贪心法


```cpp
    int maxSubArray(vector<int>& nums) {
        //转移方程为，以当前节点结尾的最大的串，看前面的最大串的结果，如果为负数就算了。然后这个过程中的最大值就是全局的最大值
        if (nums.empty())
            return 0;
        vector<int> result(nums.size(), 0);//其实可以拷贝一份;
        result[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (result[i-1] > 0)
                result[i] = result[i-1];
            result[i] += nums[i];
        }
        return *max_element(result.begin(),result.end());
    }
```

### 代码分析
这里使用了辅助空间，空间复杂度为0(n);

## 贪心算法 不用辅助空间

```cpp
    int maxSubArray(vector<int>& nums) {
        //转移方程为，以当前节点结尾的最大的串，看前面的最大串的结果，如果为负数就算了。
        if (nums.empty())
            return 0;
        int sum = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            sum=nums[i] += max(0, sum);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
```

## 动态规划
只要一出现最小最大的字眼，就适合用动态规划。这里的思路是当前节点的最大和为当前节点的前面所有和减去当前节点之前的最小和。
```cpp
    int maxSubArray(vector<int>& nums) {
        //转移方程为，以当前节点结尾的最大的串，看前面的最大串的结果，如果为负数就算了。
        if (nums.empty())
            return 0;
        int sum = nums[0];
        int maxSum = nums[0];
        int minSum = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            minSum = min(sum,minSum);
            sum += nums[i];
            maxSum = max(maxSum,sum - minSum);
        }
        return maxSum;
    }
```