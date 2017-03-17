---
title: 147-insertion-sort-list
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem

[147-insertion-sort-list](https://leetcode.com/problems/insertion-sort-list/#/description)

# solution
```cpp
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        while (head && head->next)
        {
            ListNode *temp = dummy;
            while (head->next->val > temp->next->val && temp != head)
                temp = temp->next;
            if (temp->next!=head->next)
            {
                ListNode *x = head->next->next;
                head->next->next = temp->next;
                temp->next = head->next;
                head->next = x;
            }
            else
            {
                head = head->next;
            }
        }
        return dummy->next;
        
    }

```