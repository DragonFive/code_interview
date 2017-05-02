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
这里可以深入理解一下回溯法是对隐式图的深度优先搜索算法。这是一种遍历所有解决方案树的方式

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

void dfs(vector<int> &nums, int pos, vector<int> &list, vector<vector<int>> &result)
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
### 程序流程 
![dfs的递归堆栈图][1]

### 复杂度分析

状态数为所有可能的组合数$ O(2^n)$, 生成每个状态所需的时间复杂度近似为$ O(1)$, 如[1] -> [1, 2], 故总的时间复杂度近似为 $O(2^n)$.
使用了临时空间list保存中间结果，list 最大长度为数组长度，故空间复杂度近似为$ O(n)$.

## 法2：使用位操作的方法


```cpp
vector<vector<int> > subsets( vector<int> & nums )
{
    vector<vector<int> > result;
    if (nums.empty())
	  return result;
	long long combinations = pow(2,nums.size());
	for (long long i = 0; i < combinations; i++)
	{
	    vector<int> list;
	    for (long long j = 0; j < nums.size(); j++)
	    {
	        if ((i>>j) & 1) // 这里注意是按位与操作
	            list.push_back(nums[j]);
	    }
	    result.push_back(list);
	}
	
	return result;
}

```
### 程序流程分析

先知道所有解决方案的个数，然后对每一个解决方案找一个二进制组合进行映射，接下来就遍历这个二进制组合的每一位。

### 复杂度分析
总共有$ O(2^n) $ 个数要取，每个数要遍历它所有的位数n，所以时间复杂度为$ O(2^nn) $
而空间复杂度为$ O(n) $


## 法3：走所有回溯法的流程
```cpp
vector<vector<int> > subsets( vector<int> & nums )
{
    vector<vector<int> > result;
    if (nums.empty())
	  return result;
	long long combinations = pow(2,nums.size());
	for (long long i = 0; i < combinations; i++)
	{
	    vector<int> list;
	    for (long long j = 0; j < nums.size(); j++)
	    {
	        if ((i>>j) & 1)
	            list.push_back(nums[j]);
	    }
	    result.push_back(list);
	}
	
	return result;
}

int MAXCANDIDATES = 2;
void backtrack(vector<int> &a, int k, int input,vector<vector<int> > & result )
{
    int c[MAXCANDIDATES]; /*这次搜索的候选 */
    int ncandidates; /* 候选数目 */
    int i; /* counter */
    if (is_a_solution(a,k,input))
        process_solution(a,k,input,result);
    else {
        k = k+1;
        construct_candidates(a,k,input,c,&ncandidates);
        for (i=0; i<ncandidates; i++) {
            a[k] = c[i];
            backtrack(a,k,input,result);
        }
    }
}
bool is_a_solution(vector<int> &a, int k , int input)
{
    if (k == input)
        return true;
    return false;
}
void construct_candidates(vector<int> &a,int k,int input,int c[] ,int *ncandidates)
{
    c[0] = 0;
    c[1] = 1;
    *ncandidates = 2;
}
void process_solution(vector<int> &a,int k,int input,vector<vector<int> > & result)
{
    vector<int> list;
    for (int i = 0; i < input; i++)
        if (a[i] == 1)
            list.push_back(i);
    result.push_back(list);
}
```

### 程序流程分析


### 复杂度分析

总共有$ O(2^n) $ 个数要取，每个数要遍历它所有的位数n，所以时间复杂度为$ O(2^nn) $
而空间复杂度为$ O(n) $
# reference

[LeetCode: Subsets 解题报告](http://www.cnblogs.com/yuzhangcmu/p/4211815.html)
[全面解析回溯法：算法框架与问题求解](http://www.cnblogs.com/wuyuegb2312/p/3273337.html)
[lecture15-backtracking](http://7xojrx.com1.z0.glb.clouddn.com/docs/algorithm-exercise/docs/lecture15-backtracking.pdf)


  [1]: https://www.github.com/DragonFive/CVBasicOp/raw/master/1493690746610.jpg