---
title: 34-search-for-range
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem

[34-search-for-range](https://leetcode.com/problems/search-for-a-range/?tab=Description)

## similiar problem 

[lintv61 search for a range](http://www.lintcode.com/en/problem/search-for-a-range/)

# solution

## ordinary solution
```cpp
    vector<int> searchRange(vector<int>& nums, int target) {
       //先findFirst
       vector<int> ret;
       if (nums.empty())
       {
           ret.push_back(-1);
           ret.push_back(-1);
           return ret;
       }
       int len = nums.size();
       
       int i = 0, j = len - 1;
       while ( i <= j)
       {
           int k = i + (j - i)/2;
           if ( nums[k] == target)
           {
               int t = k;
               while (k > 0 && nums[k - 1] == target)
                  k--;
               ret.push_back(k);
               while (t < len -1 && nums[t + 1] == target)
                  t ++;
               ret.push_back(t);
               return ret;
           }
           if ( nums[k] > target)
               j = k - 1;
           else
               i = k + 1;
       }
       ret.push_back(-1);
       ret.push_back(-1);
       return ret;
    }
```

## 真正的求上下界的方法

```cpp
    vector<int> searchRange(vector<int>& nums, int target) {
       //先findFirst
       vector<int> ret(2, -1);
       if (nums.empty())
           return ret;
       int len = nums.size();
       
       int i = -1, j = len;
       while ( i + 1 < j )
       {
           int k = i + (j - i)/2;
           if ( nums[k] < target)
               i = k;
           else
               j = k;
       }
       if (j < len && nums[j] != target || j == len && nums[i] != target)
           return ret;
       ret[0] = j;
       i = j - 1, j = len;
       while (i + 1 < j)
       {
           int k = i + (j - i)/2;
           if (nums[k] > target)
             j = k;
           else
             i = k;
       }
       ret[1] = i;
       return ret;
    }
```
