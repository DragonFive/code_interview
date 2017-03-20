---
title: 234-palindrome-linked-list
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---


# problem
[234-palindrome-linked-list](https://leetcode.com/problems/palindrome-linked-list/#/description)
# solution

```cpp
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return false;
        if (head->next == NULL)
            return true;
        //先使用快慢链表找到中间节点，然后反转判断;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //对slow后面的进行反转;
        fast = slow->next;
        slow->next = NULL;
        slow = NULL;
        while ( fast != NULL)
        {
            ListNode *tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        fast = slow;
        slow = head;
        //下面进行比较
        while (fast != NULL)
        {
            if (fast->val != slow->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
        
    }

```