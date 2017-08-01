# source

[链表中倒数第k个结点](https://github.com/gatieme/CodingInterviews/tree/master/015-%E9%93%BE%E8%A1%A8%E4%B8%AD%E5%80%92%E6%95%B0%E7%AC%ACk%E4%B8%AA%E7%BB%93%E7%82%B9)
# solution
```cpp
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	ListNode *first = pListHead; 
        ListNode *second = pListHead;
        if (pListHead == NULL || k <= 0)
            return NULL;
        //先找到隔着k个的下一个;
        int i = 1;
        while (first->next!=NULL && i < k)
        {
            first = first->next;
            i++;
        }
        if (first->next == NULL && i!= k)
            return NULL;
        while (first->next!=NULL)
        {
        	first = first->next;
            second = second->next;
        }
        return second;
    }
```
