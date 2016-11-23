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