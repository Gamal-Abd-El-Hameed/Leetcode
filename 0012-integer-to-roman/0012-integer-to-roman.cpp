class Solution {
public:
    string intToRoman(int num) {
        string romanRes;
        int numOfDigits = 1 + static_cast<int> (log10(num)), exponent, currDigit;
        while (numOfDigits--) {
            exponent = (int)pow(10, numOfDigits);
            currDigit = num / exponent;
            num = num % exponent;
            romanRes += getRomanValOf(currDigit, numOfDigits);
        }
        return romanRes;
    }
private:
    string getRomanValOf(int digit, int position) {
        char ones, fives, tens;
        switch (position) {
            case 0:
                ones = 'I', fives = 'V', tens = 'X';
                break;
            case 1:
                ones = 'X', fives = 'L', tens = 'C';
                break;
            case 2:
                ones = 'C', fives = 'D', tens = 'M';
                break;
            default:
                ones = 'M';
                break;
        }
        return getRomanValOf(digit, ones, fives, tens);
    }

    string getRomanValOf(int digit, char ones, char fives, char tens) {
        string res;
        switch (digit) {
            case 1:
            case 2:
            case 3:
                res = string(digit, ones);
                break;
            case 4:
                res = string(1, ones) + string(1, fives);
                break;
            case 5:
                res = string(1, fives);
                break;
            case 6:
            case 7:
            case 8:
                res = string(1, fives) + string(digit - 5, ones);
                break;
            case 9:
                res = string(1, ones) + string(1, tens);
                break;
            default:
                break;
        }
        return res;
    }
};