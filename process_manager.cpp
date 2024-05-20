#include <iostream>

using namespace std;

// This should be inheritable
class Process {
private:
    int ID = -1, AT = -1, BT = -1, PR = -1, QL = -1;
    int CT, TAT, WT;
    bool isUsed = false;

public:
    void Run() {
        cout << "Add a Process";
    }
};