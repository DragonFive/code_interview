---
title: 24-swap-nodes-in-pairs
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem
[24-swap-nodes-in-pairs](https://leetcode.com/problems/swap-nodes-in-pairs/#/description)

# solution

```cpp
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *fast = head->next;
        ListNode *slow = new ListNode(0);
        slow->next = head;
        head = fast;
        while (fast)
        {
            slow->next->next = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            
            slow = slow->next->next;
            if (fast->next->next == NULL)
                break;
            fast = fast->next->next->next;
        }
        return head;
    }
```