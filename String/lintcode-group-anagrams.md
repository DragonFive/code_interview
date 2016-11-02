---
title: lintcode-group-anagrams
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---


# 题目来源 
[Anagrams](http://www.lintcode.com/en/problem/anagrams/)
# 解法
## 双层循环法

```cpp
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        vector<string> result;
        const int strs_size = strs.size();
        int *appended = new int[strs_size];//数组的大小一定要是常量; 除非它是动态划分的;这种链表其实可以用vector替代
        //vector<bool> visited(strs.size(), false); 初始化很方便;
        memset(appended, 0, sizeof(int)*strs_size);
        for (int i = 0; i < strs.size()-1; i++)
        {
            if (appended[i])
                continue;
            const int charNums = 26;
            int charNum[charNums] = {0};
            //先统计自己;
            for (int j = 0; j < strs[i].length(); j++)
                charNum[strs[i][j] - 'a']++;
            //然后与其它元素进行比较;
            for (int j = i+1; j < strs.size(); j++)
            {
                //判断是否访问过;
                if (appended[j])
                    continue;
                //首先判断长度是否一致
                if (strs[j].length() != strs[i].length())
                    continue;
                //其实上面的两个可以替换为  if (appended[j] || strs[j].length() != strs[i].length())
                //统计这个里面的元素
                int charNumB[charNums] = {0};
                for (int k = 0; k < strs[j].length(); k++)
                    charNumB[strs[j][k] - 'a']++;
                //比较两个是否一样;
                int k = 0;
                for (; k < charNums; k++)
                    if (charNum[k] != charNumB[k])
                        break;
                if (k != charNums)
                    continue;
                //到这里说明碰到一个一样的;
                if (!appended[i])//一定要注意相同的字符串的情况，和前面的相同字符统计一样;
                    result.push_back(strs[i]);
                appended[i] = 1;
                appended[j] = 1;
                result.push_back(strs[j]);
            }
        }
        return result;
    }
```

## 排序和hashmap法
下面的multimap用的非常巧,即用到了一对多的红黑树  又用到了自动排序
```cpp
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        vector<string> result;
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
        for (hashIter = multiHash.begin(); hashIter != multiHash.end(); hashIter++)
            if (multiHash.count(hashIter->first) > 1)
                result.push_back(hashIter->second);
        return result;
    }
```

## leetcode类似题目
## 参考资料

[C++ 标准模板库STL multimap 使用方法与应用介绍（一） - 王世晖的学习记录 - 博客频道 - CSDN.NET](http://blog.csdn.net/wangshihui512/article/details/8925145)

[c++中map与unordered_map的区别 - wolfrevoda的专栏 - 博客频道 - CSDN.NET](http://blog.csdn.net/batuwuhanpei/article/details/50727227)

