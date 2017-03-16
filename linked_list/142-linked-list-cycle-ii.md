---
title: 142-linked-list-cycle-ii
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem

[142-linked-list-cycle-ii]https://leetcode.com/problems/linked-list-cycle-ii/#/description()

扩展问题：

判断两个单链表是否相交，如果相交，给出相交的第一个点（两个链表都不存在环）。

比较好的方法有两个：

一、将其中一个链表首尾相连，检测另外一个链表是否存在环，如果存在，则两个链表相交，而检测出来的依赖环入口即为相交的第一个点。

二、如果两个链表相交，那个两个链表从相交点到链表结束都是相同的节点，我们可以先遍历一个链表，直到尾部，再遍历另外一个链表，如果也可以走到同样的结尾点，则两个链表相交。

这时我们记下两个链表length，再遍历一次，长链表节点先出发前进(lengthMax-lengthMin)步，之后两个链表同时前进，每次一步，相遇的第一点即为两个链表相交的第一个点。
# solution
法一：hash法
```cpp
    ListNode *detectCycle(ListNode *head) {
        //使用hash来保存每一个位置，如果这个位置再次被访问到，那就是了;
        if (head==NULL)
            return NULL;
        unordered_set<ListNode *> hashNode;
        ListNode *cur = head;
        while (cur)
        {
            if (hashNode.find(cur) == hashNode.end())
                hashNode.push_back(cur);
            else
                return cur;
            cur = cur->next;
        }
        return NULL;
        
    }
```

法二：数学推导出个公式法
```cpp
    ListNode *detectCycle(ListNode *head) {
        //使用hash来保存每一个位置，如果这个位置再次被访问到，那就是了;
        if (head==NULL)
            return NULL;
        //先使用快慢指针找到相交点位置，然后再从起点跑起来
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (fast == NULL || fast->next==NULL)
            return NULL;
        fast = head;
        while (fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
```

# 参考资料

[判断链表是否有环，以及环的位置，和两个交叉链表相交的位置](http://www.cnblogs.com/missair/archive/2010/08/05/1793492.html)