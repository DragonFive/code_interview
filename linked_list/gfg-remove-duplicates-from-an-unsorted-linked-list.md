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