class Solution {
public:
    bool isIsomorphic(string s, string t) { // "badc"
        //"baba"
        unordered_map<char, char> s2t, t2s;
        for (int i = 0; i < s.length(); i++) {
            if (s2t.find(s[i]) == s2t.end() && t2s.find(t[i]) == t2s.end()) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            }
            else if (s2t[s[i]] != t[i])
                return false;
        }
        return true;
    }
};