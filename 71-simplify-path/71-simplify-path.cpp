class Solution {
public:
    string simplifyPath(string path) {
    stack<string> newPath;
    int n = path.length(), i = 0;
    char ch, secondChar;
    while(i < n) {
        ch = path[i];
        if(ch == '.') {
            string temp;
            temp += ch;
            ++i;
            while(i < n) {
                secondChar = path[i];
                if(secondChar == '/')
                    break;
                temp += secondChar;
                ++i;
            }
            if(temp == "..") {
                if(!newPath.empty())
                    newPath.pop();
            }
            else if(temp != ".")
                newPath.push(temp);
        }
        else if(ch != '/') {
            string temp;
            temp += ch;
            ++i;
            while(i < n) {
                secondChar = path[i];
                if(secondChar == '/')
                    break;
                temp += secondChar;
                ++i;
            }
            newPath.push(temp);
        }
        ++i;
    }
    path.clear();
    while(!newPath.empty()) {
        path = "/" + newPath.top() + path;
        newPath.pop();
    }
    if(path.empty())
        return "/";
    return path;
}
};