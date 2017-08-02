# source

[45-圆圈中的最后一个](https://github.com/gatieme/CodingInterviews/tree/master/045-%E5%AD%A9%E5%AD%90%E4%BB%AC%E7%9A%84%E6%B8%B8%E6%88%8F(%E5%9C%86%E5%9C%88%E4%B8%AD%E6%9C%80%E5%90%8E%E5%89%A9%E4%B8%8B%E7%9A%84%E6%95%B0))

# solution

## 循环链表方法
是约瑟夫换问题，使用循环链表，可以使用list来表示链表，list实现的是链表，vector实现的是数组


```cpp
    int LastRemaining_Solution(int n, int m)
    {
        if (n==0 || m==1)
            return -1;
        //先创建一个链表;
        list<int> childs;
        for (int i = 0; i < n; i++)
            childs.push_back(i);
        //接下来遍历知道只剩下一个元素;
        list<int>::iterator lit = childs.begin();
        while (childs.size() > 1)
        {
            //找到第m个元素;
            for (int i = 1; i < m; i++)
            {
                lit++;
                if (lit == childs.end())
                    lit = childs.begin();
            }
            //删除lit指向的这个元素;
            list<int>::iterator tmp = lit;
            lit++;
            if (lit == childs.end())
            	lit = childs.begin();
            childs.erase(tmp);
        }
        return *lit;
    }

```



