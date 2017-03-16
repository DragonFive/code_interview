---
title: 143-reorder-list
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem

[143-reorder-list](https://leetcode.com/problems/reorder-list/#/description)

# solution

```cpp
    void reorderList(ListNode* head) {
        //如果不足长度就算了;
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        //先计算反转的位置
        int len = 0;
        ListNode * cur = head;
        while (cur!=NULL)
        {
            len++;
            cur = cur->next;
        }
        int pos = (len + 3)/2;
        //然后对那个玩意进行反转
        cur = head;
        for (int i = 1; i < pos - 1; i++)
            cur = cur->next;
        ListNode *large = cur->next;
        cur->next = NULL;
        ListNode *pre = NULL;
        cur = large;
        while (cur!=NULL)
        {
            large = cur->next;
            cur->next = pre;
            pre =cur;
            cur = large;
        }
        //pre为起点的进入小的
        cur = head;
        while (pre!=NULL)
        {
            large = cur->next;
            cur->next = pre;
            ListNode *tmp = pre->next;
            pre->next = large;
            pre = tmp;
            cur = large;
            
        }

    }
```