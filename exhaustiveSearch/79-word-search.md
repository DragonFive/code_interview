---
title: 79-word-search
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem

[79-word-search](https://leetcode.com/problems/word-search/#/description)
# solution

```
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;
        if (word.empty())
            return true;
        vector<vector<int> > visited(board.size() , vector<int>(board[0].size(), false) );
        //寻找下一个可能的点;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, word, i, j ,visited, 0))
                    return true;
            }
        }
        return false;
        
    }
    bool dfs(vector<vector<char>>& board, string word, int row, int col, vector<vector<int> > &visited, int ind)
    {
        
        //从row和col找第一个元素，找不到就返回false;
        if (visited[row][col] == false && board[row][col] == word[ind])
        {
            if (word.size() - 1 == ind)
                return true;
            visited[row][col] = true;
            //下面开始递归;
            if (col > 0 && dfs(board, word, row, col-1, visited, ind+1) )
                return true;
            if (col < board[0].size()-1 && dfs(board, word, row, col+1, visited, ind+1) )
                return true;
            if (row > 0 && dfs(board, word, row-1, col, visited, ind+1) )
                return true;
            if (row < board.size()-1 && dfs(board, word, row+1, col, visited, ind+1) )
                return true;
            visited[row][col] = false;
        }
        return false;
        
    }
```

# reference