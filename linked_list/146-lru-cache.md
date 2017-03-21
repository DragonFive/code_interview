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

2. 使用hash表 和头尾哑节点  以及双向链表

```cpp
struct LinkNode{
	int key;
	int value;
	LinkNode *next;
	LinkNode *pre;
	LinkNode(int _key, int _value) :key(_key), value(_value), pre(NULL), next(NULL){}
};
class LRUCache {
public:
	LinkNode *head;
	LinkNode *tail;//这个链表也很有意思,根据它的操作，设计确定它在尾部插入，在头部删除冗余;
	unordered_map<int, LinkNode *> keyLink;//记录了当前的key，以及其对应的节点;
	int cap;
	LRUCache(int capacity) {
		cap = capacity;
		head = new LinkNode(0, 0);
		tail = new LinkNode(0, 0);
		head->next = tail;
		tail->pre = head;
	}

	int get(int key) {
		//如果有这个key，把它在链表中挪到最后.
		unordered_map<int, LinkNode *>::iterator umt = keyLink.find(key);
		if (umt == keyLink.end())
			return -1;
		//把这个点挪到首节点;
		move2head(umt->second);
		//返回其值;
		return umt->second->value;
	}
	void move2head(LinkNode *cur)
	{
		if (cur == head->next)
			return;
		LinkNode * pre = cur->pre;
		cur->pre = head;
		pre->next = cur->next;
		cur->next = head->next;
		head->next->pre = cur;
		head->next = cur;
		pre->next->pre = pre;

	}
	void put(int key, int value) {
		//如果已经有这个值就替换;
		unordered_map<int, LinkNode *>::iterator umt = keyLink.find(key);
		if (umt != keyLink.end())
		{
			umt->second->value = value;
			move2head(umt->second);
			return;
		}
		//如果不存在，判断是否需要删除节点;
		if (keyLink.size() == cap)
		{
			LinkNode *tmp = tail->pre;
			tail->pre = tmp->pre;
			tmp->pre->next = tail;
			keyLink.erase(tmp->key);
			delete tmp;
		}
		//然后插入新节点;
		LinkNode *newNode = new LinkNode(key, value);
		newNode->next = head->next;
		if (head->next != NULL)
			head->next->pre = newNode;
		newNode->pre = head;
		head->next = newNode;
		keyLink[key] = newNode;
	}
};
```