---
title: 172-Remove-Element
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# source
[27 Remove Element](https://leetcode.com/problems/remove-element/)

## similiar problem 

[lintcode 172 Remove Element](http://www.lintcode.com/en/problem/remove-element/)

# solution
## 使用STL容器

需要记住避免一些方法的坑 remove和erase都有各自的坑，remove其实并不会真的把数据删掉，erase删完之后的iterator也没有用了。

注意时间复杂度是O(n^2)
```cpp
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        A.erase(remove(A.begin(),A.end(),elem),A.end());
        return A.size();
    }
```

或者 
```cpp
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        vector<int>::iterator it = A.begin();
        for (; it != A.end();)
            if (*it == elem)
                it = A.erase(it);
            else
                it++;
        return A.size();
    }
```
## 两根指针法 



# reference
[STL Vector remove()和erase()的使用](http://blog.csdn.net/yockie/article/details/7859330)


[九章算法 remove element解题](http://www.jiuzhang.com/solutions/remove-element/)