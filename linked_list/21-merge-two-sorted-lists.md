---
title: 21-merge-two-sorted-lists
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem 
[21-merge-two-sorted-lists](https://leetcode.com/problems/merge-two-sorted-lists/#/description)

# solution
```cpp
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode *dummy = new ListNode(0);
        dummy->next = NULL;
        ListNode *result = dummy;
        while (cur1 != NULL && cur2 != NULL)
        {
            if (cur1->val < cur2->val)
            {
                result->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                result->next = cur2;
                cur2 = cur2->next;
            }
            result = result->next;
        }
        if (cur1 == NULL && cur2 != NULL)
            result->next = cur2;
        else 
            result->next = cur1;
        return dummy->next;
    }
```