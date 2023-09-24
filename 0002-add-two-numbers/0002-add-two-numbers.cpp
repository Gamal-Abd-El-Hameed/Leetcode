class Solution {
private:
    string listToNumber(ListNode* node) {
        string res;
        while (node) {
            res += node->val + '0';
            node = node->next;
        }
        return res;
    }
    string addTwoStrings(const string &s1, const string &s2) {
        string res;
        int sum = 0, i = 0, j = 0;
        while (i < s1.length() && j < s2.length()) {
            sum += (s1[i] - '0') + (s2[j] - '0');
            if (sum > 9) {
                res += '0' + (sum % 10);
                sum = sum / 10;
            }
            else {
                res += '0' + sum;
                sum = 0;
            }
            i++; j++;
        }
        while (i < s1.length()) {
            sum += (s1[i] - '0');
            if (sum > 9) {
                res += '0' + (sum % 10);
                sum = sum / 10;
            }
            else {
                res += '0' + sum;
                sum = 0;
            }
            i++;
        }
        while (j < s2.length()) {
            sum += (s2[j] - '0');
            if (sum > 9) {
                res += '0' + (sum % 10);
                sum = sum / 10;
            }
            else {
                res += '0' + sum;
                sum = 0;
            }
            j++;
        }
        if (sum)
            res += '0' + sum;
        return res;
    }
    ListNode* numToList(string num) {
        auto node = new ListNode();
        auto curr = node;
        for (int i = 0; i < num.length(); i++) {
            char digit = num[i];
            curr->val = digit - '0';
            if (i < num.length() - 1) {
                curr->next = new ListNode();
                curr = curr->next;
            }
        }
        return node;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string firstNum = listToNumber(l1);
        string secondNum = listToNumber(l2);
        string additionRes = addTwoStrings(firstNum, secondNum);
        return numToList(additionRes);
    }
};