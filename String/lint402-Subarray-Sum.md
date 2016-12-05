---
title: lint138-Subarray-Sum
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# source

[ lintcode 138-Subarray-Sum](http://www.lintcode.com/en/problem/subarray-sum/)

## similiar problem 

[geeks for geeks, Find if there is a subarray with 0 sum](http://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/)

[lintcode139 Subarray Sum Closest](http://www.lintcode.com/en/problem/subarray-sum-closest/)

# solution
可以先把问题转化，f(i) 表示从下标0到下标i求和的结果，那如果f(i) == f(j)就说明在i和j之间的数的和为0。在一串数中检索两个相等的数可以使用哈希表呀。

**哈希表法**
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

**排序法**

```cpp
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        vector<int> result;
        if (nums.empty())
            return result;
        int numSum = nums.size();
        vector<pair<int, int> > sum_index(numSum + 1); //和-下标对;
        int lastSum = 0;
        //先统计sum和index键值对;
        for (int i = 0; i < numSum; i++)
        {
            lastSum = lastSum + nums[i];
            sum_index[i+1].first  = lastSum;
            sum_index[i+1].second = i + 1;
        }
        //接下来排序然后看看相邻的两个是否一样;
        sort(sum_index.begin(), sum_index.end());
        for (int i = 1; i < numSum + 1; i ++)
            if (sum_index[i].first == sum_index[i - 1].first)
            {
                result.push_back(sum_index[i - 1].second);
                result.push_back(sum_index[i].second - 1);
                break;
            }
        return result;
    }

```

# extention 
[geeks for geeks  find subarray with given sum](http://www.geeksforgeeks.org/find-subarray-with-given-sum/)


[lintcode139 Subarray Sum Closest](http://www.lintcode.com/en/problem/subarray-sum-closest/)


[stack overflow How to find the subarray that has sum closest to zero or a certain value](http://stackoverflow.com/questions/16388930/how-to-find-the-subarray-that-has-sum-closest-to-zero-or-a-certain-value-t-in-o)