class Solution {
public:
    string simplifyPath(string path) {
    istringstream iss(path);
    vector<string> tokens;
    string token;
    while(getline(iss, token, '/')) {
        if(token == "." || token == "")
            continue;
        tokens.push_back(token);
    }
    vector<string> ans;
    for(string t: tokens) {
        if(t == "..") {
            if(!ans.empty())
                ans.pop_back();
        }
        else
            ans.push_back(t);
    }
    if(ans.empty())
        return "/";
    ostringstream oss;
    for(string t: ans)
        oss << "/" << t;
    return oss.str();
}
};