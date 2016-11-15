---
title: lint192-Wildcard-Matching
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# source
[lintcode Wildcard-Matching ](http://www.lintcode.com/en/problem/wildcard-matching/#)

相似题目

[leetcode 44 Wildcard-Matching](https://leetcode.com/problems/wildcard-matching/)
# solution

```cpp
bool isMatch(string m, string n)
{
	// write your code here
	// 找* 起点
	char * begins = (char *)m.c_str(), *beginp = (char *)n.c_str();
	while (*beginp != '*' && *beginp != '\0' && *begins != '\0')
		if (*beginp != *begins && *beginp != '?')
			return false;
		else
		{
			beginp++; begins++;
		}
	if (*beginp == '\0' && *begins == '\0')
		return true;
	if (*beginp == '\0' || *begins == '\0' && *beginp != '*')
		return false;
	while (*beginp == '*')
		beginp++;
	while (*beginp != '\0' && *begins != '\0')
	{
		//下面找到下一个*的位置      
		char * endp = beginp;
		while (*endp != '*' && *endp != '\0')
			endp++;
		// 从beginp到endp
		//分情况讨论如果 *endp == '*'走下面
		if (*endp == '*')
		{
			char *finds = findSubStr(begins, beginp, endp);
			if (finds == NULL)
				return false;
			begins = finds + (endp - beginp);
			beginp = endp;
			while (*beginp == '*')
				beginp++;
		}
		else
		{
			//右对齐进行比较
			char * ends = begins;
			while (*ends != '\0')
				ends++;
			while ((*ends == *endp || *endp == '?') && ends >= begins && endp >= beginp)
			{
				ends--;
				endp--;
			}
			if (endp < beginp)
				return true;
			else
				return false;

		}
	}
	if (*begins == '\0' && *beginp != '\0')
		return false;
	else
		return true;
}
char * findSubStr(char *begins, char *beginp, char *endp)
{
	char * s = begins, *p = beginp;
	while (*s != '\0')
	{
		while ( *p != '\0' && *s != '\0' && (*p == *s || *p == '?'))
		{
			p++; s++;
		}
		if (p == endp)
			return begins;
		if (*s == '\0')
			return NULL;
		p = beginp;
		s = ++begins;
	}
	return NULL;
}
```