---
title: 2017-3-7-lint183-wood-cut
tags: 在河之洲,算法,lintcode
grammar_cjkRuby: true
---


# problem
[lintcode183 wood cut](http://www.lintcode.com/en/problem/wood-cut/)

# solution
注意两点
1. 注意边界条件
2. 取的是最大值而不是最小值.
```cpp
    int woodCut(vector<int> L, int k) {
        // write your code here
        //先找到L里面最短的;
	// write your code here
	//先找到L里面最短的;
	if (L.empty())
		return 0;
	int maxLen = 0;
	for (int i = 0; i < L.size(); i++)
		if (L[i] > maxLen)
			maxLen = L[i];
	//再进行切分;
	int i = 1, j = maxLen;
	while (i + 1 < j)
	{
		int m = i + (j - i) / 2;
		int num = getCutNum(L, m);
		if (num < k)
			j = m;
		else
			i = m;
	}
	if (j != maxLen && i != 1)
		return i;
	if (j == maxLen)
		if (getCutNum(L, j) >= k)
			return j;
		else
			return i;
	else if (getCutNum(L, 1) >= k)
		return 1;
	else
		return 0;

        
    }
    int getCutNum(vector<int> L, int len)
    {
        int num = 0;
        for (int i = 0 ; i < L.size(); i++)
            num += L[i] / len;
        return num;
    }

```