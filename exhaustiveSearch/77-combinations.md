---
title: 77-combinations
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem

[77-combinations](https://leetcode.com/problems/combinations/#/description)


# solution
## 使用返回+全盘便利的方法 这种方法其实只是在二岔树的时候比较好用
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

## 使用subset的模板

```
    vector<vector<int> > combine(int n, int k) {
        //要么循环，要么递归，可以先用递归.
        vector<vector<int> > result;
        if (k == 0 || n < k)
            return result;
        vector<int> list;
        dfs(1, n, k, list, result);
        return result;
    }
    void dfs(int start, int n, int k, vector<int> &list, vector<vector<int> > &res)
    {
        if (list.size() == k)
        {
            res.push_back(list);
            return;
        }
        //下面开始访问当前的节点;
        for (int i = start; i <= n - k + list.size() + 1; i++)
        {
            list.push_back(i);
            dfs( i + 1, n, k, list, res );
            list.pop_back();
        }
        return;
    }
```

# reference


[combinations](https://algorithm.yuanbin.me/zh-hans/exhaustive_search/combinations.html)