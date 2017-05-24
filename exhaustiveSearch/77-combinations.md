---
title: 77-combinations
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem

[77-combinations](https://leetcode.com/problems/combinations/#/description)


# solution

```
    vector<vector<int> > combine(int n, int k) {
        //要么循环，要么递归，可以先用递归.
        return helper(1, n, k);
    }
    vector<vector<int> > helper(int start, int n, int k)
    {
        vector<vector<int> > result;
        if (start > n || k <= 0)
            return result;
        if (start == n && k == 1)
        {
            vector<int> vec;
            vec.push_back(start);
            result.push_back(vec);
            return result;
        }
        for (int j = start; j <= n - k + 1; j++)
        {
            vector<vector<int> > rightRes = helper(j + 1, n, k - 1);
            if (rightRes.empty())
            {
                vector<int> vec;
                vec.push_back(j);
                result.push_back(vec);
            }
            for (int i = 0; i < rightRes.size(); i++)
            {
                vector<int> vec;
                vec.push_back(j);
                vec.insert(vec.end(), rightRes[i].begin(), rightRes[i].end());
                result.push_back(vec);
            }
        }
        return result;
    }
```

# reference
