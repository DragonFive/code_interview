---
title: lint415-valid-pal
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---
# 题目来源

[415 valid palindrome](http://www.lintcode.com/en/problem/valid-palindrome/)

## leedcode相似题目 

[125 valid palindrome](https://leetcode.com/problems/valid-palindrome/)

# 解法
字符串的回文判断问题，由于字符串可随机访问，故逐个比较首尾字符是否相等最为便利，即常见的『两根指针』技法。此题忽略大小写，并只考虑字母和数字字符
## 两根指针法
判断链表是否有环的方法是快慢指针法

```cpp
    bool isPalindrome(string& s) {
        // Write your code here
        int len = s.length();
        int start = 0, end = len - 1;
        while (end >= start)
        {
            while (!(isdigit(s[start]) || isalpha(s[start]) ) ) 
                start++;
            while (!(isdigit(s[end]) || isalpha(s[end]) ) )
                end--;
            if (end >= start && (s[end] - s[start]) % ('A' - 'a') != 0) 
                return false;
            start++;
		    end--;
        }
        return true;
    }
```

# 启示
需要记住c语言的一些字符串处理api:  tolower 把字符转化为小写，  isalnum 判断一个字符是否是字母或者数字 , isdigit判断字符是否是数字  isalpha 判断是否是字母

# 引申到回文链表

[geeksforgeeks  如何判断一个链表是否是回文链表](http://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/)

题目中用到了数组的随机访问，所以可以使用两根指针的方式分别向后和向前比较。但如果是链表的话就不能往前返回了，需要用新的思路

1. 使用一个stack
2. 先找到队列的中间，然后对后一半进行翻转，比较前后两半的队列，如果一样把后一半再翻转回来




