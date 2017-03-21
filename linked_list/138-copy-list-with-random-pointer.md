---
title: 138-copy-list-with-random-pointer
tags: 在河之洲,算法,leetcode
grammar_cjkRuby: true
---


# problem
[138-copy-list-with-random-pointer](https://leetcode.com/problems/copy-list-with-random-pointer/#/description)

# solution

```cpp
    RandomListNode *copyRandomList(RandomListNode *head) {
        //先遍历按next,拷贝，并保存两个hash；
        if (head == NULL)
            return NULL;
        unordered_map<RandomListNode *,RandomListNode *> oldNew; //新老对应map
        unordered_map<RandomListNode *,RandomListNode *> oldRan; //random原来指的位置;
        RandomListNode *oldCur = head->next;
        RandomListNode *result = new RandomListNode(head->label);
        RandomListNode *newCur = result;
        //处理好NewCur的random;
        if (head->random != NULL)
            oldRan[newCur] = head->random;
        //处理好新旧对应;
        oldNew[head] = newCur;
        while (oldCur)
        {
            newCur->next = new RandomListNode(oldCur->label);
            newCur = newCur->next;
            //处理好NewCur的random;
            if (oldCur->random!=NULL)
                oldRan[newCur] = oldCur->random;
            //处理好新旧对应;
            oldNew[oldCur] = newCur;
            oldCur = oldCur->next;
        }
        //遍历一遍hash表，修改新链表对应的值;
        unordered_map<RandomListNode *,RandomListNode *>::iterator umt = oldRan.begin();
        for (; umt != oldRan.end(); umt++)
        {
            umt->first->random = oldNew[umt->second];
        }
        return result;
    }
```