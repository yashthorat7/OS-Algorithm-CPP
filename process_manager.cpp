#include <iostream>
#include <vector>

using namespace std;

// This should be inheritable
class Process {
private:
    int ID = -1, AT = -1, BT = -1, PR = -1, QL = -1;
    int CT, TAT, WT;
    bool isUsed = false;

    vector<int> SetProcesses() {
        int n;
        cout << "Enter the no of Processes: ";
        cin >> n;

        cout << "\nEnter the Process nos - Arrival Times - Burst Times\t{Eg ::4 5 18}" << endl;
        for (int i = 0; i < n; i++) {
            cout << ":: ";
            cin >> ID >> AT >> BT;;
        }
        
        return {ID, AT, BT, PR, QL};
    }

public:
    vector<int> Run(int choice) {
        
        return SetProcesses();
    }
};