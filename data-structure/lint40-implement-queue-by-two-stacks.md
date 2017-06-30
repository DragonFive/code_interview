---
title: lint40-implement-queue-by-two-stacks
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lint40-implement-queue-by-two-stacks](http://www.lintcode.com/en/problem/implement-queue-by-two-stacks/)
# solution
```cpp
class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;

    MyQueue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        int temp = top();
        stack2.pop();
        return temp;
    }

    int top() {
        // write your code here
        if (stack2.size() == 0)
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top() );
                stack1.pop();
            }
        }
        int temp = stack2.top();
        return temp;
    }
};
```