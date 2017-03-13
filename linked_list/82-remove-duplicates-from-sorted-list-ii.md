---
title: 82-remove-duplicates-from-sorted-list-ii
tags: 在河之洲,算法,leetcode
grammar_cjkRuby: true
---

# problem
[82-remove-duplicates-from-sorted-list-ii](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/#/description)
# solution

```cpp
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode *pre = head;
        bool dup = false;
        ListNode *cur = pre->next;
        ListNode * pref = pre;
        while (cur)
        {
            if (pre->val == cur->val)
            {
                if (pre == head)
                    head = cur;
                else
                    pref->next = cur;//修改pre前面的next;
                delete pre;
                pre = cur;
                cur = cur->next;
                dup = true;
            }
            else if (dup)
            {
                if (pre == head)
                {
                    head = cur;
                }
                else
                    pref->next = cur;
                delete pre;
                pre = cur;
                cur = cur->next;
                dup = false;
            }
            else
            {
                pref = pre;
                pre = cur;
                cur = cur->next;
            }
        }
        if (dup)
        {
                if (pre == head)
                {
                    head = NULL;
                }
                else
                    pref->next = NULL;
                delete pre;
                pre = NULL;
        }
        return head;
    }
```