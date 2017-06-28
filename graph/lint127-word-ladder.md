---
title: lint127-word-ladder
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lint127-word-ladder](https://leetcode.com/problems/word-ladder/#/description)

# solution

## dfs
```cpp
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.empty())
            return -1;
        if (beginWord == endWord)
            return 0;
        //下面开始计算步数;
        vector<bool> visited(wordList.size(), false);
        //先去掉字典中与beginWord一样的元素;
        for (int i = 0 ; i < wordList.size(); i++)
            if (beginWord == wordList[i])
                visited[i] = true;
        int len = dfs(beginWord, endWord, visited, wordList);
        if (len > wordList.size()+1)
            return 0;
        return len;
        
    }
    
    int dfs(string beginWord, string endWord, vector<bool> &visited, vector<string >& wordList)
    {
        if (beginWord == endWord)
            return 1;
        //遍历wordList中没有visited过的元素;
        int res = wordList.size()+1;
        for (int i = 0; i < wordList.size(); i++)
        {
            if (visited[i] == true)
                continue;
            //判断一步可达;
            int diff = 0;
            for (int j = 0; j < beginWord.length(); j++)
                if (beginWord[j] != wordList[i][j])
                    diff++;
            if (diff != 1)
                continue;
            visited[i] = true;
            res =  min(res, dfs(wordList[i], endWord, visited, wordList));
            visited[i] = false;
        }
        return res+1;
    }
```

### code analysis
深度优先搜索，需要剪枝防止图中环的存在，但这里还是出现了超时


## bfs

```cpp
   int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.empty())
            return -1;
        if (beginWord == endWord)
            return 0;
        vector<bool> visited(wordList.size(), false);
        //先去掉字典中与beginWord一样的元素;
        for (int i = 0 ; i < wordList.size();i++)
            if (wordList[i] == beginWord)
                visited[i] = true;
        int len = bfs(beginWord, endWord, visited, wordList);
        if (len > wordList.size()+1)
            return 0;
        return len;
        
    }
    
    int bfs(string beginWord, string endWord, vector<bool> &visited, vector<string >& wordList)
    {
        if (beginWord == endWord)
            return 1;
        //遍历wordList中没有visited过的元素;
        int res = 0;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty())
        {
            int len = q.size();
            
            for (int i = 0 ; i < len; i++)
            {
                string beginWord = q.front();
                q.pop();
                if (beginWord == endWord)
                {
                    return res+1;
                }
                //把这个节点的所有后续节点加入里面;
                for (int j = 0 ; j < wordList.size(); j++)
                {
                    if (visited[j] == true)
                        continue;
                    int diff = 0;
                    for (int k = 0; k < beginWord.length(); k++)
                        if (beginWord[k] != wordList[j][k])
                            diff++;
                    if (diff != 1)
                        continue;
                    q.push(wordList[j]);
                    visited[j] = true;
                }
            }
            res++;
        }
        
        return 0;
    }
```
