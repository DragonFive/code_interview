---
title: 61-rotate-list
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

使用双指针来找到特定的位置;
# problem
[61-rotate-list](https://leetcode.com/problems/rotate-list/#/description)
# solution

```cpp
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        //计算长度并找到最后一个点和应该断的点
        ListNode *tail = head;
        ListNode *place = head;
        int len = 0;
        while (tail)
        {
            tail=tail->next;
            len++;
        }
        k = k % len;
        if (k == 0)
            return head;
        tail = head;
        while (k-- && tail!=NULL)
            tail = tail->next;
        while (tail->next)
        {
            tail = tail->next;
            place = place->next;
        }
        //找到应该断的点;
        ListNode *tmp = place->next;
        place->next = NULL;
        tail->next = head;
        head = tmp;
        return head;
    }
```