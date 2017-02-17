---
title: lint-60-search-insert-position 
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# problem

[lint60 search insert position]()

# solution

```cpp
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if (A.empty())
            return 0;
        int i = 0, j = A.size();
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (A[mid] == target)
                return mid;
            if (A[mid] < target)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return i;
    }
```