#include <string>
#include <unordered_map>

// 滑动窗口 (难点在于判断是否t的所有元素都在slide window里, 用两个hash map保存)
class Solution {
public:
    bool isAll(std::unordered_map<char, int> &s, std::unordered_map<char, int> &t) {
        for (auto tItem : t) {
            if (s.count(tItem.first) == 0 || s[tItem.first] < tItem.second) {
                return false;
            }
        }
        return true;
    }

    std::string minWindow(std::string s, std::string t) {
        int start = 0;
        int end = 0;
        int minLen = std::numeric_limits<int>::max();
        std::string ret;
        std::unordered_map<char, int> sMap;
        std::unordered_map<char, int> tMap;
        for (int i = 0; i < t.length(); ++i) {
            if (tMap.count(t[i]) == 0)
                tMap[t[i]] = 1;
            else
                tMap[t[i]]++;
        }

        while (end < s.length()) {
            if (sMap.count(s[end]) == 0) {
                sMap[s[end]] = 1;
            } else {
                sMap[s[end]]++;
            }

            if (isAll(sMap, tMap)) {
                while (start <= end) { 
                    if (isAll(sMap, tMap)) {
                        sMap[s[start]]--;
                        if (sMap[s[start]] == 0) {
                            sMap.erase(s[start]);
                        }
                    } else {
                        break;
                    }
                    start++;
                }
                if (minLen > end - (start - 1) + 1) {
                    minLen = end - start + 2;
                    ret = s.substr(start-1, minLen);
                }
            }
            end++;
        }

        return ret;
    }
};