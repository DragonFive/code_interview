---
title: 86-partition-list
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem
[86-partition-list](https://leetcode.com/problems/partition-list/#/description)


# solution

```cpp
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return NULL;
        //先找到尾结点;
        ListNode * tail = head;
        int count = 1;
        while (tail->next)
        {
            tail = tail->next;
            count++;
        }
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        //考察每一个节点;
        ListNode * cur = dummy;
        while (count)
        {
            //这里需要注意的是最后一个节点,其实是不用考察的点;
            if (cur->next->val >= x && cur->next != tail)
            {
                ListNode * tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = NULL;
                tail->next = tmp;
                tail = tmp;
            }
            else
                cur = cur->next;
            count--;
        }
        return dummy->next;
        
    }
```