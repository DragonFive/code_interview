---
title: lintcode-anagrams
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# 题目来源 

[ lintcode Two Strings Are Anagrams](http://www.lintcode.com/en/problem/two-strings-are-anagrams/)

# 解法
## 使用哈希表统计词频

### 第一种方法使用c++的map集合来做:
```cpp

bool anagram(string s, string t) {
	// write your code here
	if (s.size() != t.size())
		return false;

	map<char, int> maps, mapt;
	for (string::size_type ids = 0; ids < s.size(); ids++)
	{
		if (maps.find(s[ids]) == maps.end())
			maps[s[ids]] = 1;
		else
			maps[s[ids]] ++;
	}
	for (string::size_type idt = 0; idt < s.size(); idt++)
	{
		if (mapt.find(t[idt]) == mapt.end())
			mapt[t[idt]] = 1;
		else
			mapt[t[idt]] ++;
	}
	if (maps!=mapt)
		return false;
	return true;
}
```

### 第二种方法使用数组对每个字符进行统计

```cpp
bool anagram(string s, string t) {
	// write your code here
	if (s.size() != t.size())
		return false;

	int charNum[256] = {0};//初始化一个全0的数组;
	for(int i = 0;i < s.length();i++)
	{
	    charNum[s[i]]++;
	    charNum[t[i]]--;
	}
	for(int i = 0;i < s.length();i++)
	    if(charNum[s[i]] != 0)
	        return false;
	return true;
}
```

## 使用排序比较法
```cpp
bool anagram(string s, string t) {
	// write your code here
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	if(s != t)
	    return false;
	return true;
}
```

