# source
[037-两个链表的第一个公共节点](https://github.com/gatieme/CodingInterviews/tree/master/037-%E4%B8%A4%E4%B8%AA%E9%93%BE%E8%A1%A8%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E5%85%AC%E5%85%B1%E7%BB%93%E7%82%B9)

这个题有非常多的解法
# solution

```cpp
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        //遍历第一个链表，放在哈希表中。
        if (pHead1 == NULL || pHead2 == NULL)
            return NULL;
        set<ListNode *> nodes;
        ListNode *cur = pHead1;
        while (cur != NULL){
            nodes.insert(cur);
            cur = cur->next;
        }
        //遍历第二个链表，知道找到set里有的
        cur = pHead2;
        while (cur!=NULL){
            if (nodes.find(cur) != nodes.end())
                return cur;
            cur = cur->next;
        }
        return NULL;
            
    }
```
