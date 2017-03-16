---
title: 142-linked-list-cycle-ii
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem

[142-linked-list-cycle-ii]https://leetcode.com/problems/linked-list-cycle-ii/#/description()
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