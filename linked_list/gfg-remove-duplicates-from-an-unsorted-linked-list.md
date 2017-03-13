---
title: gfg-remove-duplicates-from-an-unsorted-linked-list
tags: 在河之洲,算法,geeksforgeeks
grammar_cjkRuby: true
---

# problem
[gfg-remove-duplicates-from-an-unsorted-linked-list](http://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/)

# solution
unordered_set也是hash
```cpp
void removeDuplicates(struct Node *start)
{
    // Hash to store seen values
    unordered_set<int> seen;
 
    /* Pick elements one by one */
    struct Node *curr = start;
    struct Node *prev = NULL;
    while (curr != NULL)
    {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end())
        {
           prev->next = curr->next;
           delete (curr);
        }
        else
        {
           seen.insert(curr->data);
           prev = curr;
        }
        curr = prev->next;
    }
}
```

使用Map来做
```cpp
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;

        // C++ 11 use unordered_map
        // unordered_map<int, bool> hash;
        map<int, bool> hash;
        hash[head->val] = true;
        ListNode *curr = head;
        while (curr->next != NULL) {
            if (hash.find(curr->next->val) != hash.end()) {
                ListNode *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                hash[curr->next->val] = true;
                curr = curr->next;
            }
        }

        return head;
    }
```