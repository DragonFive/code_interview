---
title: 16-3Sum-Closest
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem 


[16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/)


# solution 

## 排序+两根指针法 

```cpp
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.empty() || nums.size() < 3)
            return -1;
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        const int nums_size = nums.size();
        for (int i = 0; i < nums_size; )
        {
            int j = i + 1, k = nums_size - 1;
            while (j < k)
            {
                if (abs(nums[i] + nums[j] + nums[k] - target) < abs(result - target))
                    result = nums[i] + nums[j] + nums[k];
                if (result == target)
                    return target;
                if (nums[i] + nums[j] + nums[k] > target)
                {
                    k--;
                    while (k > 0 && nums[k] == nums[k + 1])
                        k--;
                }
                else
                {
                    j++;
                    while (j < nums_size -1 && nums[j] == nums[j - 1])
                        j++;
                }
                    
            }
            i++;
            while (i < nums_size && nums[i] == nums[i - 1])
                i++;
        }
        return result;
    }

```