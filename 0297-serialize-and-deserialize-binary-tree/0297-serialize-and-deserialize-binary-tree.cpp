class Codec {
private:
    char delimiter = ',';
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return ".";
        string leftSerialized = serialize(root->left);
        string rightSerialized = serialize(root->right);
        return to_string(root->val) + delimiter + leftSerialized + delimiter + rightSerialized;
    }

    TreeNode* deserialize(string data) {
        istringstream input(data);
        return deserializeHelper(input);
    }

    TreeNode* deserializeHelper(istringstream &input) {
        string token;
        getline(input, token, delimiter);
        if (token == ".")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserializeHelper(input);
        root->right = deserializeHelper(input);
        return root;
    }
};