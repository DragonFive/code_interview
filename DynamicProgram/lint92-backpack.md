---
title: lint92-backpack
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem

[lint92-backpack](http://www.lintcode.com/en/problem/backpack/)
# solution
## solution1. 使用二维数组的背包模板来做
这里物品下表从0开始，而容量是从1开始算的。所以物品下标j表示的是前j个物品的总价值。而容量下标i表示的是容量为i时的价值。
```
    int backPack(int m, vector<int> A) {
        // write your code here
        if (A.empty() || m ==0)
            return 0;
        vector<vector<int> > result = vector<vector<int> >(m+1, vector<int>(A.size()+1, 0) );
        //然后进行双循环
        for (int i = 0; i < m+1; i++)//物品重量累加
            for (int j = 0; j < A.size(); j++)//物品数目累加
                if (A[j] <= i)
                    result[i][j+1] = result[i][j] > result[i-A[j]][j] + A[j]?result[i][j]: result[i-A[j]][j] + A[j];
                else
                    result[i][j+1] = result[i][j];
        return result[m][A.size()];
        
    }
```

### code analysis
代码会超内存

## solution2.一维数组
```
    int backPack(int m, vector<int> A) {
        // write your code here
        if (A.empty() || m ==0)
            return 0;
        vector<int>  result = vector<int>(m+1, 0);
        //然后进行双循环
        for (int j = 0; j < A.size(); j++)//物品数目累加
            for (int i = m; i >0; i--)//物品重量累加
                if (A[j] <= i)
                    result[i] = result[i-A[j]] + A[j] > result[i] ?  result[i-A[j]] + A[j] :result[i] ;
        return result[m];
        
    }
	```