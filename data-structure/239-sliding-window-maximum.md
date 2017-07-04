---
title:  239-sliding-window-maximum
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[239-sliding-window-maximum](https://leetcode.com/problems/sliding-window-maximum/#/description)

# solution
```cpp
        void push(deque<int> &dq, int num)
        {
            while (!dq.empty() && num > dq.back()) 
                dq.pop_back();
            dq.push_back(num);
        }
        void pop(deque<int> &dq, int num)
        {
            if (!dq.empty() && num == dq.front())
                dq.pop_front();
        }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.empty() || nums.size()<k)
            return result;
        deque<int> dq;
        for (int i = 0; i < k; i++)
            push(dq,nums[i]);
        
        result.push_back(dq.front());
        for (int i = k; i < nums.size(); i++)
        {
            pop(dq,nums[i-k]);
            push(dq,nums[i]);
            result.push_back(dq.front());
        }
        return result;
        
    }
```


# reference

[九章算法](http://www.jiuzhang.com/solutions/sliding-window-maximum/)
