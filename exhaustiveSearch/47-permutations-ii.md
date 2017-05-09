---
title: 47-permutations-ii
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem

[47-permutations-ii(https://leetcode.com/problems/permutations-ii/#/description)

# solution
## 回溯法+剪枝
```
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty())
            return result;
        vector<bool> visited(nums.size(), false);
        vector<int> list;
        
        sort(nums.begin(),nums.end());
        backTracking(nums, list, visited, result);
        return result;
    }
    void backTracking(vector<int> &nums, vector<int> &list, vector<bool> &visited, vector<vector<int>> &result)
    {
        if (list.size() == nums.size())
        {
            result.push_back(list);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            //下面进行剪枝干;
            if (visited[i] || (i!=0 && nums[i] == nums[i-1] && !visited[i-1]))
                continue;
            visited[i] = true;
            list.push_back(nums[i]);
            backTracking(nums, list, visited, result);
            list.pop_back();
            visited[i] = false;
        }
    }
```
## 字典序法
参见46-permutations
# reference