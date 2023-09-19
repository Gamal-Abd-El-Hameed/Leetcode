class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<>());
        int h = 0;
        for (int citation:citations) {
            if (citation >= h + 1)
                h++;
            else
                break;
        }
        return h;
    }
};