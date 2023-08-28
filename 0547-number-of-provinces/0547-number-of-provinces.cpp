class Solution {
private:
    int doFind(int n, int parents[]) {
        int p = parents[n];
        while (p != parents[p]) {
            parents[p] = parents[parents[p]];
            p = parents[p];
        }
        return p;
    }

    int doUnion(int n1, int n2, int parents[], int ranks[]) {
        int p1 = doFind(n1, parents);
        int p2 = doFind(n2, parents);
        if (p1 == p2)
            return 0;
        if (ranks[p1] > ranks[p2]) {
            parents[p2] = p1;
            ranks[p1] += ranks[p2];
        }
        else {
            parents[p1] = p2;
            ranks[p2] += ranks[p1];
        }
        return 1;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = n;
        int parents[n], ranks[n];
        fill_n(ranks, n, 1);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    ans -= doUnion(i, j, parents, ranks);
                }
            }
        }
        return ans;
    }
};