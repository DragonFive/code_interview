---
title: 122-best-time-to-buy-and-sell-stock-ii
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[122-best-time-to-buy-and-sell-stock-ii](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/#/description)

# solution
```cpp
    int maxProfit(vector<int>& prices) {
        //找到一段自增段;
        if (prices.empty()||prices.size() == 1)
            return 0;
        int maxElem = -1, minElem = -1, result = 0;
        while ((maxElem < (int)prices.size()) && (minElem < (int)prices.size()) )
        {
            //先找局部最小值;
            int i = maxElem + 1;
            for (; i < prices.size() - 1; i++)
                if (prices[i+1] > prices[i])
                    break;
            minElem = i;
            int j = i + 1;
            for (; j < prices.size() -1; j++)
                if (prices[j+1] < prices[j])
                    break;
            maxElem = j;
            if (maxElem > minElem && maxElem < (int)prices.size())
                result += prices[maxElem] - prices[minElem];
        }
        return result;
    }
```