---
title: 146-lru-cache
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem
[146-lru-cache](https://leetcode.com/problems/lru-cache/#/description)

# solution
1. 使用vector管理
```cpp
struct data{
	int key;
	int value;
	data(int _key, int _value) :key(_key), value(_value){}
};
class LRUCache {
public:
	vector<data> obj;
	int cap;
	LRUCache(int capacity) {
		cap = capacity;

	}
	int get(int key) {
		//先找到所在的位置,然后挪到第一个;
		int i = getPos(key);
		if (i == -1)
			return -1;
		//把第i个元素挪到第一个;
		int tkey = obj[i].key;
		int tval = obj[i].value;
		obj.erase(obj.begin() + i);
		put(tkey, tval);
		return tval;
	}
	int getPos(int key)
	{
		int osize = obj.size();
		int i = 0;
		for (; i < osize; i++)
		{
			if (obj[i].key == key)
				break;
		}
		if (i >= osize)
			return -1;
		return i;
	}
	void put(int key, int value) {
		//放在最前头;		
		int pos = getPos(key);
		//检查是否已经有这个数了;
		if (pos != -1)
		{
			//删除它；
			obj.erase(obj.begin() + pos);
		}
		if (obj.size() == cap)
			obj.erase(obj.end() - 1);
		data d(key, value);
		obj.insert(obj.begin(), d);
	}
};
```