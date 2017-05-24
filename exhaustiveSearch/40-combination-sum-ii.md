---
title: 40-combination-sum-ii
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[40-combination-sum-ii](https://leetcode.com/problems/combination-sum-ii/#/description)
# solution
```
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        if (candidates.empty())
            return result;
        vector<int> list;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, list, result, 0, 0);
        return result;
    }
    void dfs(vector<int> &cand, int target, vector<int> &list, vector<vector<int> > &res, int pos, int sums)
    {
        if (sums == target)
        {
            res.push_back(list);
            return;
        }
        if (sums > target || pos >= cand.size())
            return;
        for (int i = pos; i < cand.size();)
        {
            
            list.push_back(cand[i]);
            sums += cand[i];
            dfs(cand, target, list, res, i+1, sums);
            sums -= cand[i];
            list.pop_back();
            i++;
            while (cand[i] == cand[i-1] && i < cand.size())
                i++;
        }
    }
```

# reference
