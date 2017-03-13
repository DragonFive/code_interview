---
title: 83-remove-duplicates-from-sorted-list
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem

[83-remove-duplicates-from-sorted-list](https://leetcode.com/problems/remove-duplicates-from-sorted-list/#/description)

# solution

```cpp
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode *pre = head;
        while (pre->next)
        {
            ListNode * cur = pre->next;
            if (cur->val == pre->val)//删掉当前内存;
            {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else
                pre = cur;
        }
        return head;
    }
	```