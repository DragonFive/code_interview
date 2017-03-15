---
title: lint141-linked-list-cycle
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem
[lint141-linked-list-cycle](https://leetcode.com/problems/linked-list-cycle/#/description)

# solution
```cpp
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast!=slow)
        {
            if (fast == NULL || fast->next == NULL)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
```