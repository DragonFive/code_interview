---
title: lint115-unique-paths-ii
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# problem
[lint115-unique-paths-ii](http://www.lintcode.com/en/problem/unique-paths-ii/)

# solution
```cpp
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> nums(n, 0);
        nums[0] = 1 - obstacleGrid[0][0];
        for (int i = 1; i < n; i++)
            if (obstacleGrid[0][i] == 1 )
                nums[i] = 0;
            else
                nums[i] = nums[i-1];
        //接下来判断
        for (int i = 1; i < m; i++)
        {
            if ( obstacleGrid[i][0] == 1)
                nums[0] = 0;
            for (int j = 1; j < n; j++)
                if (obstacleGrid[i][j] == 1)
                    nums[j] = 0;
                else
                    nums[j] += nums[j-1];
        }
        return nums[n-1];        
    }

```