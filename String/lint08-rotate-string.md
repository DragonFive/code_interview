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
常见的翻转法应用题，仔细观察规律可知翻转的分割点在从数组末尾数起的offset位置。先翻转前半部分，随后翻转后半部分，最后整体翻转。

三次翻转法 需要注意的是分段点在哪里
```cpp
    void rotateString(string &str,int offset)
    {
        //wirte your code here
        if (str.empty())
            return;
        int len = str.size();
        offset = offset % len;
        if (offset == 0)
            return;
        reverseStr(str, 0, len - offset - 1);
        reverseStr(str, len - offset, len - 1);
        reverseStr(str, 0, len - 1);
    }
    void reverseStr(string &str, int start, int end)
    {
        while(end > start)
        {
            char temp  = str[start];
            str[start] = str[end];
            str[end]   = temp;
            start++;
            end--;
        }
    }
```

翻转一次时间复杂度近似为 O(n), 原地交换的空间复杂度为 O(1), 非原地交换的空间复杂度为 O(n). 总共翻转3次，所以总的时间复杂度为O(n), 空间复杂度为 O(1) 或者 O(n).