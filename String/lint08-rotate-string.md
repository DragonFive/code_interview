---
title: lint08-rotate-string
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# 题目来源 

[lintcode 8. rotate string](http://www.lintcode.com/en/problem/rotate-string/)

# 解法

## 暴力求解法

```cpp
    void rotateString(string &str, int offset){
        // wirte your code here
        // 交换的方法
        if (str.empty())
            return;
        int len = str.length();
        offset = offset % len;
        if (offset == 0)
            return;
    	for (int i = len - offset; i < len; i++)
    	{
    		int yuzhi = i - (len - offset);
    		for (int j = i; j > yuzhi; j--)
    			swap(str, j, j - 1);
    	}
    }
    void swap(string &str, int i, int j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
```

## 三次翻转法
