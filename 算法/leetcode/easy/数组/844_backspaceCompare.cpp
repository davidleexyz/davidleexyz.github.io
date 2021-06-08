#include <vector>
#include <string>

// 带backspace的比较 双指针并且记录需要忽略的字符数量
// 反向遍历并且记录skip count
// 1. 如果当前字符是# 则count++, index--
// 2. 如果是字符, 则判断count是否为0; 是则比较, 不是则count--, index--
class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        int skipS = 0, skipT = 0;
        int sp = s.length() - 1;
        int tp = t.length() - 1;

        while (sp >= 0 || tp >= 0) {
            // 遍历需要完全忽略的字符直到skipS为0
            while (sp >= 0) {
                if (s[sp] == '#') {
                    sp--;
                    skipS++;
                } else if (skipS > 0) {
                    skipS--;
                    sp--;
                } else {
                    break;
                }
            }

            while (tp >= 0) {
                if (t[tp] == '#') {
                    tp--;
                    skipT++;
                } else if (skipT > 0) {
                    skipT--;
                    tp--;
                } else {
                    break;
                }
            }

            // 判断有效字符
            if (sp >= 0 && tp >= 0) {
                if (s[sp] != t[tp]) {
                    return false;
                }
            } else {
                // sp或者tp中一个已经为空
                if (sp >= 0 || tp >= 0) {
                    return false;
                }
            }
            sp--;
            tp--;
        }
        return true;
    }
};