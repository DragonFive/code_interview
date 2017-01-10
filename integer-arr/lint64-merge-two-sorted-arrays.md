---
title: lint64-merge-two-sorted-arrays
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# source

[lint64 merge-two-sorted-arrays](http://www.lintcode.com/en/problem/merge-two-sorted-arrays/


# solution

```cpp
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        if (A.empty() && B.empty())
            return A;
        const int sizeA = A.size();
        const int sizeB = B.size();
        vector<int> result(sizeA + sizeB);
        int i = 0, j = 0, k = 0; 
        for (; i < sizeA + sizeB; ++i)
        {
            if (j >= sizeA || k >= sizeB)
                break;
            if (A[j] <= B[k])
                result[i] = A[j++];
            else
                result[i] = B[k++];
        }
        while (j < sizeA)
            result[i++] = A[j++];
        while (k < sizeB)
            result[i++] = B[k++];
        return result;
    }
```