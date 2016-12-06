---
title: 01-Two-Sum
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

# source

[1. Two Sum](https://leetcode.com/problems/two-sum/)


## similiar problem

[lintcode56 tow sum](http://www.lintcode.com/en/problem/two-sum/)

[lint138-Subarray-Sum](https://github.com/DragonFive/Leetcode/blob/master/String/lint138-Subarray-Sum.md)
# solution

```cpp
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> numsIndexMap;
        const int size = nums.size();
        vector<int> ret;
        // 建立哈希表
        for (int i = 0; i < size; ++i)
        {
            numsIndexMap[nums[i]] = i + 1;
        }
        // 寻找配对
        for (int i = 0; i < size; i++)
            if (numsIndexMap.find(target - nums[i]) != numsIndexMap.end() && i != numsIndexMap[target - nums[i]])
            {
                ret.push_back(i + 1);
                ret.push_back(numsIndexMap[target - nums[i]]);
                break;
            }
         return ret;       
        
    }
```

其实上面先建哈希表再用的方式并不好

```cpp
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> numsIndexMap;
        const int size = nums.size();
        vector<int> ret;
        // 建立哈希表
        for (int i = 0; i < size; i++)
        {
            if (numsIndexMap.find(target - nums[i]) != numsIndexMap.end())
            {
                ret.push_back(numsIndexMap[target - nums[i] ] );
                ret.push_back(i);
                break;
            }
            else
            {
                numsIndexMap[nums[i] ] = i;
            }
        }
        return ret;       
        
    }

```

也可以使用先排序然后使用两根指针的方法，但是这种方法的空间复杂度其实是比较大的

