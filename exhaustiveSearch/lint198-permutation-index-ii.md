---
title: lint198-permutation-index-ii
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# source
[lint198-permutation-index-ii](http://www.lintcode.com/en/problem/permutation-index-ii/)
这里需要考虑重复元素，有无重复元素最大的区别在于原来的1!, 2!, 3!...等需要除以重复元素个数的阶乘，颇有点高中排列组合题的味道。
# solution

```
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        if (A.empty())
            return 0;
        long long result = 1, factor = 1, res = 1;
        unordered_map<int, int> sameNum;
        for (long long i = A.size() -1 ; i >= 0 ; i--)
        {
            long long rank = 0;
            bool same = false;
            for (long long j = i+1; j < A.size(); j++)
            {
                if (A[i] > A[j])
                    rank++;
                //同时要记录有多少个重复到数字出现;
                else if (A[i] == A[j] && same == false)
                {
                    same = true;
                    if (sameNum.find(A[i]) == sameNum.end() )
                    {
                        sameNum[i] == 2;
                        res *= 2;
                    }
                    else
                    {
                        sameNum[i]++;
                        res *= sameNum[i];
                    }
                }
                
            }
            result += rank * factor / res;
            factor *= (A.size() - i);
        }
        return result;
    }
```
# reference

