---
title: 78-subsets
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem 
[78-subsets](https://leetcode.com/problems/subsets/#/description)
求一个集合的所有子集。
# solution
## 法1：递归回溯法
这里可以深入理解一下回溯法是对隐式图的深度优先搜索算法。

```
vector<vector<int> > subsets( vector<int> & nums )
{
    vector<vector<int> > result;
    if (nums.empty())
	  return result;
	
	vector<int> list;//这里也可以使用stack;
	dfs(nums, 0 , list, result);
	
	return result;
}

void dfs(vector<int> &nums, int pos, vector<int> &list. vector<vecor<int>> &result)
{
    result.push_back(list);
	for (int i = pos; i < nums.size(); i++)
	{
	    list.push_back(nums[i]);
		dfs(nums, i+1, list, result);
		list.pop_back();
	}
}
```

# reference

[LeetCode: Subsets 解题报告](http://www.cnblogs.com/yuzhangcmu/p/4211815.html)

