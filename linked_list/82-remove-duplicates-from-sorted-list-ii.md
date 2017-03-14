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


# 使用哑节点

```cpp
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode * cur = dummy;
        while (cur->next)
        {
            //按数据段进行搜索,而不是按单个数据搜索，运用了上下文信息，与
            if (cur->next->next!=NULL && cur->next->val == cur->next->next->val)
            {
                int preval = cur->next->val;
                //删除这个数据段，等于val的所有节点;
                while (cur->next!=NULL && cur->next->val == preval)
                {
                    ListNode * tmp = cur->next;
                    cur->next = tmp->next;
                    delete tmp;
                    tmp = NULL;
                }
            }
            else
                cur = cur->next;
        }
        return dummy->next;
    }
```