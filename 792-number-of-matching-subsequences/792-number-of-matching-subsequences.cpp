class Solution {
public:
    int bs(vector<int> &arr, int x) {
        int start = 0,end = arr.size()-1,ans = -1, mid;
        while (start <= end) {
            mid = (start + end) >> 1;

            if (arr[mid] <= x)
                start = mid + 1;
            else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans==-1 ? ans : arr[ans];
    }    

    int numMatchingSubseq(string s, vector<string>& words) {
        
	    unordered_map<char,vector<int>> mp;
        for(int i=0;i<s.length();i++)
            mp[s[i]].push_back(i);                  
        int count = words.size();
		int prev, x;
        for(string w : words) {
            prev = -1;
            for(char ch : w) {
                x = bs(mp[ch],prev);
                if(x == -1) {
                    --count;
                    break;
                }
                else
                    prev = x;                
            }
        }
        return count;
    }
};