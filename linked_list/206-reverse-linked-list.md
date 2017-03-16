---
title: 206-reverse-linked-list
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem
[](https://leetcode.com/problems/reverse-linked-list/#/description)

# solution

```cpp
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)   
            return NULL;
        ListNode *pre = head;
        ListNode *cur = head->next;
        pre->next =NULL;
        while (cur)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
```