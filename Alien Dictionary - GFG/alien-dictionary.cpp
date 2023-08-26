//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findOrder(string dict[], int N, int K) {
        unordered_map<int, unordered_set<int>> G;
        int indegree[K] = {};
        for (int i = 1; i < N; i++) {
            int j = 0;
            for (; j < min(dict[i - 1].size(), dict[i].size()); j++) {
                if (dict[i - 1][j] != dict[i][j]) {
                    G[dict[i - 1][j] - 'a'].insert(dict[i][j] - 'a');
                    break;
                }
            }
//            if (j == dict[i].size() && j < dict[i - 1].size()) return "";
        }
        for (auto &it : G) {
            for (int to : it.second) {
                indegree[to]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (G.count(i) && indegree[i] == 0) q.push(i);
        }
        string ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans += u + 'a';
            for (int v : G[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return ans.size() == G.size() ? ans : "";
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends