---
title: 39-combination-sum
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[39-combination-sum](https://leetcode.com/problems/combination-sum/#/description)

# solution
```
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        if (candidates.empty())
            return result;
        vector<int> list;
        dfs(candidates, target, list, result, 0, 0);
        return result;
    }
    void dfs(vector<int> &cand, int target, vector<int> &list, vector<vector<int> > &res, int start, int sums)
    {
        if (sums == target)
        {
            res.push_back(list);
            return;
        }
        if (sums > target)
            return;
        for (int i = start; i < cand.size(); i++)
        {
            list.push_back(cand[i]);
            sums += cand[i];
            dfs(cand, target, list, res, i, sums);
            sums -= cand[i];
            list.pop_back();
        }
        return;
    }
```