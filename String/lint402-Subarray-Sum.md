---
title: lint402-Subarray-Sum
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# source

[ lintcode 402-Subarray-Sum](http://www.lintcode.com/en/problem/subarray-sum/)

## similiar problem 

[geeks for geeks, Find if there is a subarray with 0 sum](http://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/)

# solution
可以先把问题转化，f(i) 表示从下标0到下标i求和的结果，那如果f(i) == f(j)就说明在i和j之间的数的和为0。在一串数中检索两个相等的数可以使用哈希表呀。


```cpp
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        unordered_map<int,int> sumInd;
        sumInd[0] = 0;
        int curSum = 0;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            curSum += nums[i];
            if (sumInd.find(curSum) != sumInd.end())
            {
                result.push_back(sumInd[curSum]);
                result.push_back(i);
                break;
            }
            else
                sumInd[curSum] = i + 1;
        }
        return result;
    }
```



# 