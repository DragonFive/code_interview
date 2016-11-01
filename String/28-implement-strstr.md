---
title: 28-implement-strstr
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# 问题描述
对于一个给定的 source 字符串和一个 target 字符串，你应该在 source 字符串中找出 target 字符串出现的第一个位置(从0开始)。如果不存在，则返回 -1。

[Implement strStr() | LeetCode OJ](https://leetcode.com/problems/implement-strstr/)

[字符串查找 lintcode](http://www.lintcode.com/zh-cn/problem/strstr/)

# 说明
在面试中是否需要实现KMP算法？

不需要，当这种问题出现在面试中时，面试官很可能只是想要测试一下你的基础应用能力。当然你需要先跟面试官确认清楚要怎么实现这个题。

# 实现 

## 使用库函数 

```cpp
#include<string>

class Solution {
public:
    int strStr(string haystack, string needle) {
        int where = haystack.find(needle);
        if(where!=haystack.npos)
            return where;
        else
            return -1;
    }
};
```


##  暴力匹配法
```cpp
#include<string>

class Solution {
public:
    int strStr(string s, string t) 
    {
        int i=0;
        for(;i<int(s.length()-t.length())+1;i++)//这里要注意长度
        {
        	int j=0;
        	for(;j<t.length();j++)
        	{
        		if(s[i+j] != t[j])
        			break;
    		}
    		if(j == t.length())
    			return i;
    	}
    	return -1;
            
    }
};
```

```python
class Solution:
    def strStr(self, source, target):
        # write your code here
        if source is None or target is None:
            return -1
        for i in range(len(source)-len(target)+1):
            for j in range(len(target)):
                if source[i+j] != target[j]:
                    break
            else:
                return i
        return -1
  ```
  
  ## 优化后的KMP算法
  
  ```cpp
  void getNext(string t, int next[])
{
	next[0] = -1;
	
	int k = -1, j = 0, lent = t.size();
	
	while (j < lent - 1)
	{
		if (k == -1 || t[j] == t[k])
		{
			k++; j++;
			if (t[j] == t[k])
				next[j] = next[k];
			else
				next[j] = k;
		}
		else
			k = next[k];
	}
}
int strStr(string s, string t)
{
	if (s.empty() && t.empty())
		return 0;
	if (t.empty())
	    return 0;
	if (s.size() < t.size())
		return -1;
	
	int * next = new int[t.size()];
	getNext(t, next);

	//string::size_type ids = 0, idt = 0;//这里idt不能用size_type类型 因为可能为-1
	int ids = 0, idt = 0;
	int lens = s.size(), lent = t.size();
	while (ids < lens && idt < lent)
	{
		if (idt == -1 || s[ids] == t[idt])
		{
			ids++; idt++;
		}
		else
			idt = next[idt];
	}

	delete[] next;
	if (idt == t.size())
		return ids - idt;
	return -1;



}
  ```
  
  