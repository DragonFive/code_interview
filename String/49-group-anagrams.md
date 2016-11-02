---
title: 49-group-anagrams 
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


题目连接 
[Group Anagrams | LeetCode OJ](https://leetcode.com/problems/anagrams/)
# 解法 

```cpp
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
                // write your code here
        vector<vector<string>> result;
        typedef multimap<string,string> strStrHash;
        strStrHash  multiHash;//第一是是排序后的结果,第二个是对应的字符串;
        //先把所有的字符串排序然后放入一对多的map里面;
        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(),str.end());
            multiHash.insert(make_pair(str,strs[i]));
        }
        //把一个键有不少于两个值的值输出
        strStrHash::iterator hashIter;
    	for (hashIter = multiHash.begin(); hashIter != multiHash.end(); )
    	{
			string tempKey = hashIter->first;
			vector<string> *tempVecStr = new vector<string>();
			for (; hashIter != multiHash.upper_bound(tempKey); hashIter++)
				tempVecStr->push_back(hashIter->second);
			result.push_back(*tempVecStr);
    	}
        return result;
    }
```

# 类似题目 
