---
title: lint127-topological-sorting
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lint127-topological-sorting](http://www.lintcode.com/en/problem/topological-sorting/#)

# solution
```cpp
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode *> result;
        if (graph.empty())
            return result;
        //统计入度,找到没有指向的点作为根;
        unordered_map<DirectedGraphNode *, int> in_degree;
        for (int i = 0; i < graph.size();i++)
        {
            int neighbor_size = graph[i]->neighbors.size();
            for (int j = 0; j < neighbor_size; j++)
            {
                if ( in_degree.find(graph[i]->neighbors[j]) == in_degree.end() )
                    in_degree[graph[i]->neighbors[j]] = 1;
                else
                    in_degree[graph[i]->neighbors[j]] += 1;
            }
        }
        //找到不在map里面的那些点;
        DirectedGraphNode * root = NULL;
        for (int i = 0; i < graph.size(); i++)
        {
            if (in_degree.find(graph[i]) == in_degree.end())
            {
                root = graph[i];
                in_degree[root] = 0;
            }
        }
        if (root == NULL)
            return result;
        //下面开始bfs,定各个节点的深度;
        queue<DirectedGraphNode *> q;
        q.push(root);
        while (!q.empty())
        {
            DirectedGraphNode * cur_node = q.front();
            q.pop();
            result.push_back(cur_node);
            //访问cur_node的所有邻居;并且push;
            int nghb_size = cur_node->neighbors.size();
            for (int i = 0; i < nghb_size; i++)
            {
                
                in_degree[cur_node->neighbors[i] ] -= 1;
                if (in_degree[cur_node->neighbors[i] ] == 0)
                    q.push(cur_node->neighbors[i]);
            }
        }
        return result;
    }
```

# reference

[C++ STL中Map的按Key排序和按Value排序](http://blog.csdn.net/iicy266/article/details/11906189)

[拓扑排序](https://algorithm.yuanbin.me/zh-hans/graph/topological_sorting.html)