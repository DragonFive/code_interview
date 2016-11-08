---
title: lint415-valid-pal
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---
# 题目来源

[415 valid palindrome](http://www.lintcode.com/en/problem/valid-palindrome/)


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