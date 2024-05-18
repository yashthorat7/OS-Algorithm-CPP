#include <iostream>
#include <string>
#include <vector>
using namespace std;

class InputValidator {
private:
    bool CheckValid(string& num) {
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
    }

public:
    vector<int> InputArray(string& nums) {
        vector<int> ValidArray;
        string num;

        for (char ch : nums) {
            if (ch == ' ') {
                if (!num.empty() && CheckValid(num))
                    ValidArray.push_back(stoi(num));
                num.clear();
            } else
                num += ch;
        }

        if (!num.empty() && CheckValid(num))
            ValidArray.push_back(stoi(num));

        return ValidArray;
    }
};