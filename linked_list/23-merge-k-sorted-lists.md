---
title: 23-merge-k-sorted-lists
tags: 在河之洲,算法,leetcode,hard
grammar_cjkRuby: true
---


# problem
[23-merge-k-sorted-lists](https://leetcode.com/problems/merge-k-sorted-lists/#/description)

# solution
```cpp
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        ListNode *dummy = new ListNode(0);
        dummy->next = NULL;
        ListNode *result = dummy;
        int size = lists.size();
        int notNull = size;
        if (size == 1)
            dummy->next = lists[0];
        while (notNull > 1)
        {
            //先找到最小者;然后赋值;
            int min = INT_MAX;
            notNull = size;
            int minInd = -1;
            for (int i = 0; i < size; i++)
            {
                if (lists[i] == NULL)
                    notNull --;
                else if (lists[i]->val < min)
                {
                    min = lists[i]->val; 
                    minInd = i;
                }
            }
            if (notNull > 0)
            {
                result->next = lists[minInd];
                lists[minInd] = lists[minInd]->next;
                result = result->next;
            }
        }
        return dummy->next;
    }
```