---
title: 92-reverse-linked-list-ii
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem

[92-reverse-linked-list-ii](https://leetcode.com/problems/reverse-linked-list-ii/#/description)

需要注意的是哑节点
# solution
```cpp
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL)
            return NULL;
        if (m == n)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = head;
        ListNode *pm = head;
        int i = 1;
        while (i < m)
        {
            pre = cur;
            cur = cur->next;
            i++;
        }
        pm = cur;
        //然后下面开始反转了;
        ListNode * fa = cur;
        cur = cur->next;
        i++;
        while (i < n)
        {
            ListNode *tmp = cur->next;
            cur->next = fa;
            fa = cur;
            cur = tmp;
            i++;
        }
        ListNode *tmp = cur->next;
        cur->next = fa;
        pre->next = cur;
        pm->next = tmp;
        return dummy->next;
    }
```