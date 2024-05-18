#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>
#include <vector>
using namespace std;

class InputValidator {
private:
    bool CheckValid(string& num);

public:
    vector<int> InputArray(string& nums);
};

#endif
