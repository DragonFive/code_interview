---
title: lint176-route-between-two-nodes-in-graph 
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lint176-route-between-two-nodes-in-graph](http://www.lintcode.com/en/problem/route-between-two-nodes-in-graph/)

# solution

## dfs
图的问题为避免环的存在需要标记一个节点是否访问过。

```cpp
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        if (graph.empty())
            return false;
        unordered_set<DirectedGraphNode* > visited;//记录某个点有没有visited过;
        return dfs(graph,visited,s,t);
    }
    bool dfs(vector<DirectedGraphNode*> graph,unordered_set<DirectedGraphNode* > visited,
                  DirectedGraphNode* s, DirectedGraphNode* t){
        if (s == t)
            return true;
        vector<DirectedGraphNode *> ng = s->neighbors;
        visited.insert(s);
        int i = 0;
        for (; i < ng.size(); i++)
        {
            if (visited.find(ng[i])!=visited.end())//访问过当前节点; 
                continue;
            if (dfs(graph, visited, ng[i], t) == true)
                break;
        }
        if (i == ng.size())
            return false;
        else
            return true;
    }
```
### code analysis
时间复杂度为O(V+E), 空间复杂度为O(V). 但是因为使用来递归来处理，所以会爆栈，可以尝试使用栈结构来处理。估计内存使用量差不多


## bfs
除了深搜处理邻居节点，我们也可以采用 BFS 结合队列处理，优点是不会爆栈，缺点是空间复杂度稍高和实现复杂点。


```cpp
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        if (graph.empty())
            return false;
        unordered_set<DirectedGraphNode* > visited;//记录某个点有没有visited过;
        
        //vector<DirectedGraphNode *> ng = s->neighbors;
        
        queue<DirectedGraphNode* > nodeq;
        nodeq.push(s);
        while (!nodeq.empty())
        {
            DirectedGraphNode* pos = nodeq.front();
            nodeq.pop();
            visited.insert(pos);
            if (pos == t)
                return true;
            vector<DirectedGraphNode *> ng = pos->neighbors;
            for (int i = 0; i < ng.size(); i++)
            {
                if (visited.find(ng[i]) != visited.end() )
                    continue;
                nodeq.push(ng[i]);
            }
        }
        return false;
        
    }
```

