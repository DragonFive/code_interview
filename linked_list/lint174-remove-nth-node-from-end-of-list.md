---
title: lint174-remove-nth-node-from-end-of-list
tags: 在河之洲,算法,lintcode
grammar_cjkRuby: true
---

# problem
[lint174-remove-nth-node-from-end-of-list](http://www.lintcode.com/en/problem/remove-nth-node-from-end-of-list/)
# solution

```cpp
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        if (!head)
            return NULL;
        //先计算位置;
        int nodeNum = 0;
        ListNode *cur = head;
        while (cur)
        {
            nodeNum++;
            cur = cur->next;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        cur = dummy;
        while(nodeNum != n)
        {
            cur = cur->next;
            nodeNum--;
        }
        ListNode * tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        return dummy->next;
    }
```