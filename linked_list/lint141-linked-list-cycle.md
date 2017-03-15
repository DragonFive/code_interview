---
title: lint141-linked-list-cycle
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem
[lint141-linked-list-cycle](https://leetcode.com/problems/linked-list-cycle/#/description)

为什么有环的话，快指针一定能遇到满指针呢，因为它们相遇时一定是在环中转圈，而快指针每次比慢指针多走一步，所以两者的正向距离会慢慢变小。
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