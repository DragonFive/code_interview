---
title: 90-subsets-ii
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem

[90-subsets-ii](https://leetcode.com/problems/subsets-ii/#/description)
求一个集合的不重复的子集。
本题是[78-subsets](https://github.com/DragonFive/Leetcode/blob/master/exhaustiveSearch/78-subsets.md)的变形。 

# solution
```
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty())
            return result;
        set<vector<int>> tmp;
        vector<int> list;
        sort(nums.begin(),nums.end());
        dfs(nums, result, 0, list, tmp);
        return result;
    }
    void dfs(vector<int> & nums, vector<vector<int>> & result, int k, vector<int> &list, set<vector<int>> &tmp)
    {
        //判断list，是否已经有了;
        if (tmp.find(list) != tmp.end())
            return;
        result.push_back(list);
        tmp.insert(list);
        for (int i = k ; i < nums.size(); i++)
        {
            list.push_back(nums[i]);
            dfs(nums, result, i+1, list, tmp);
            list.pop_back();
        }
    }
```
