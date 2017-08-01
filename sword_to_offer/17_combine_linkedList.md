# source

[017-合并两个排序的链表](https://github.com/gatieme/CodingInterviews/tree/master/017-%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%8E%92%E5%BA%8F%E7%9A%84%E9%93%BE%E8%A1%A8)

# solution

```cpp
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;
        ListNode *yummy = new ListNode(0);
        yummy->next = pHead2;
        if (pHead2->val < pHead1->val){
            yummy->next = pHead2->next;
            pHead2->next = pHead1;
            pHead1 = pHead2;
        }
        ListNode *cur = pHead1;
        while (cur->next != NULL && yummy->next!=NULL){
            if (yummy->next->val < cur->next->val){
                ListNode *tmp = yummy->next;
                yummy->next = tmp->next;
                tmp->next = cur->next;
                cur->next = tmp;
            }
            cur = cur->next;
        }
        if (cur->next == NULL)
            cur->next = yummy->next;
        return pHead1;
        
    }
```

 
