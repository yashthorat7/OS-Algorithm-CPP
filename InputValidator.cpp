#include <iostream>
#include <string>
#include <vector>
using namespace std;

class InputValidator {
public:
    bool CheckValid(string& num, int avoid) {
        int n;

        if (num.empty())
            return false;

        try {
            n = stoi(num);
        } catch (const invalid_argument& ia) {
            return false;
        } catch (const out_of_range& oor) {
            return false;
        }

        return (n > 0 && n < avoid);
    }

    vector<int> InputArray(string& nums, int avoid) {
        vector<int> ValidArray;
        string num;

        for (char ch : nums) {
            if (ch == ' ') {
                if (!num.empty() && CheckValid(num, avoid))
                    ValidArray.push_back(stoi(num));
                num.clear();
            } else
                num += ch;
        }

        if (!num.empty() && CheckValid(num, avoid))
            ValidArray.push_back(stoi(num));

        return ValidArray;
    }
};