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
    stack<string> ans;
    for(string t: tokens) {
        if(t == "..") {
            if(!ans.empty())
                ans.pop();
        }
        else
            ans.push(t);
    }
    path.clear();
    while(!ans.empty()) {
        path = "/" + ans.top() + path;
        ans.pop();
    }
    if(path.empty())
        return "/";
    return path;
}
};