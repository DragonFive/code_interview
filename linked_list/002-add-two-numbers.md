---
title: 002-add-two-numbers
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem
[002-add-two-numbers](https://leetcode.com/problems/add-two-numbers/#/description)


# solution

```cpp
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode * result = l2;
        int res = 0;
        ListNode * small = l1;
        if (getLen(l1) > getLen(l2))
        {
            result = l1;
            small = l2;
        }
        ListNode * big = new ListNode(0);
        big->next = result;
        while (small)
        {
            int sum = small->val + big->next->val + res;
            big->next->val = sum % 10;
            res = sum / 10;
            big = big->next;
            small = small->next;
        }
        while (res!=0 && big->next)
        {
            int sum = big->next->val + res;
            big->next->val = sum % 10;
            res = sum / 10;
            big = big->next;
        }
        while (res!=0)
        {
            big->next = new ListNode(0);
            big->next->next = NULL;
            big->next->val = res % 10;
            res = res / 10;
            big = big->next;
        }
        return result;
        
            
    }
    int getLen(ListNode *L)
    {
        int len = 0;
        while (L)
        {
            len++;
            L = L->next;
        }
        return len;
    }

```