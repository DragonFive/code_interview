---
title: lintcode-anagrams
tags: 新建,模板,小书匠
grammar_cjkRuby: true
---

使用哈希表加快速度

```cpp
// #include <map>
// #include <algorithm>
// using namespace std;
class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if (s.size() != t.size())
            return false;
            
        map<char,int> maps,mapt;
        for (string::size_type ids = 0; ids < s.size(); ids++)
        {
            if(maps.find(s[ids]) == maps.end())
                maps[s[ids]] = 1;
            else
                maps[s[ids]] ++;
        }
        for (string::size_type idt = 0; idt < s.size(); idt++)
        {
            if(mapt.find(t[idt]) == mapt.end())
                mapt[t[idt]] = 1;
            else
                mapt[t[idt]] ++;
        }
        if(maps.size()!=mapt.size())
            return false;
        
        map<char,int>::iterator siter;
        for(siter=maps.begin();siter!=maps.end();siter++)
        {
            if(mapt.find(siter->first) == mapt.end() || siter->second != mapt[siter->first])
            {
                return false;
            }
        }
        return true;
    }
};
```