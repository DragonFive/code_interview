---
title: 148-sort-list
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem
[148-sort-list](https://leetcode.com/problems/sort-list/#/description)

# solution
归并排序
```cpp
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        //先算长度
        int len = 0;
        ListNode *cur = head;
        while (cur)
        {
            len ++;
            cur = cur->next;
        }
        //再partition
        cur = head;
        for (int i = 1; i < len / 2; i ++)
            cur=cur->next;
        ListNode *right = cur->next;
        cur->next = NULL;
        cur = sortList(head);
        right = sortList(right);
        //再合并;
        ListNode *result = NULL;
        if (cur->val < right->val)
        {
            result = cur;
            cur = cur->next;
        }
        else
        {
            result = right;
            right = right->next;
        }
        ListNode *ret  = result;
        while (cur!=NULL && right!=NULL)
        {
            if (cur->val < right->val)
            {
                result->next = cur;
                cur = cur->next;
            }
            else
            {
                result->next = right;
                right = right->next;
            }
            result = result->next;
        }
        if (cur == NULL)
            result->next = right;
        else
            result->next = cur;
        return ret;
    }
```