---
title: 203-remove-linked-list-elements
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem

[203-remove-linked-list-elements](https://leetcode.com/problems/remove-linked-list-elements/#/description)
# solution

```cpp
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next !=NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
```