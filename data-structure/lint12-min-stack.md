---
title: lint12-min-stack
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem

[lint12-min-stack](http://www.lintcode.com/en/problem/min-stack/)
# solution
```cpp
class MinStack {
public:
    stack<int> stack1;
    stack<int> stack2;//栈也只有在这种情况下,才能记录最值;
    MinStack() {
        // do initialization if necessary
        
    }

    void push(int number) {
        // write your code here
        stack1.push(number);
        if (stack2.empty() || number <= stack2.top())
            stack2.push(number);
    }

    int pop() {
        // write your code here
        int top = stack1.top();
        stack1.pop();
        if (top == stack2.top())
            stack2.pop();
		return top;
    }

    int min() {
        // write your code here
        return stack2.top();
    }
};


```

# reference
[min_stack](https://algorithm.yuanbin.me/zh-hans/data_structure/min_stack.html)