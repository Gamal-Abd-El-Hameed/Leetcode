class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
    int a[26] = {0};
    for (char i : s)
        a[i - 'a']++;
    for (char i : t)
        a[i - 'a']--;
    for (int i : a)
        if (i != 0)
            return false;
    return true;
}
};