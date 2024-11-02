#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        unordered_map<pair<string, int>, bool, hash_pair> mp;
        return helper(s, st, "", 0, mp);
    }

private:
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ (hash2 << 1);
        }
    };

    bool helper(string &s, set<string> &st, string temp, int ind, unordered_map<pair<string, int>, bool, hash_pair>& mp) {
        if (ind == s.length()) {
            return st.count(temp) == 1;
        }
        
        if (mp.count({temp, ind}) != 0) return mp[{temp, ind}];
        
        temp += s[ind];
        if (st.count(temp)) {
            mp[{temp, ind}] = helper(s, st, temp, ind + 1, mp) || helper(s, st, "", ind + 1, mp);
            return mp[{temp, ind}];
        }
        
        mp[{temp, ind}] = helper(s, st, temp, ind + 1, mp);
        return mp[{temp, ind}];
    }
};
