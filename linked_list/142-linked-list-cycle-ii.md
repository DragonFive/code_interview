---
title: 142-linked-list-cycle-ii
tags: 在河之洲,算法,小书匠
grammar_cjkRuby: true
---

# problem

[142-linked-list-cycle-ii]https://leetcode.com/problems/linked-list-cycle-ii/#/description()
# solution
法一：hash法
```cpp
    ListNode *detectCycle(ListNode *head) {
        //使用hash来保存每一个位置，如果这个位置再次被访问到，那就是了;
        if (head==NULL)
            return NULL;
        unordered_set<ListNode *> hashNode;
        ListNode *cur = head;
        while (cur)
        {
            if (hashNode.find(cur) == hashNode.end())
                hashNode.push_back(cur);
            else
                return cur;
            cur = cur->next;
        }
        return NULL;
        
    }
```

法二：数学推导出个公式法
