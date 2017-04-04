#include "utils.h"

class Solution {
    bool IfOneModi(string s, string t) {
        int diff = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) ++diff;
        }

        return diff == 1;
    }

    bool IfOneDel(string s, string t) {
        // assume s is longer

        for (int i = 0; i < t.size(); ++i) {
            if (s[i] != t[i]) {
                return s.substr(i + 1) == t.substr(i);
            }
        }

        return true;
    }

   public:
    bool isOneEditDistance(string s, string t) {
        int slen = s.size();
        int tlen = t.size();

        if (abs(slen - tlen) >= 2) return false;

        if (slen == tlen) return IfOneModi(s, t);

        if (slen > tlen) return IfOneDel(s, t);

        return IfOneDel(t, s);
    }
};
