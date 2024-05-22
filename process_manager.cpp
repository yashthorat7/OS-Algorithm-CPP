#include <iostream>
#include <vector>

using namespace std;

// This should be inheritable
class Process {
private:
    int ID = -1, AT = -1, BT = -1, PR = -1, QL = -1;
    int CT, TAT, WT;
    bool isUsed = false;

    vector<int> SetProcesses(int n) {
        cout << "\nEnter the Process nos - Arrival Times - Burst Times\t{Eg ::4 5 18}" << endl;
        for (int i = 0; i < n; i++) {
            cout << ":: ";
            cin >> ID >> AT >> BT;
        }
        
        return {ID, AT, BT, PR, QL};
    }

    vector<int> SetProcessesPri(int n) {
        cout << "\nEnter the Process nos - Arrival Times - Burst Times - Priority (less >> more)\t{Eg ::4 5 18 2}" << endl;
        for (int i = 0; i < n; i++) {
            cout << ":: ";
            cin >> ID >> AT >> BT >> PR;
        }
        
        return {ID, AT, BT, PR, QL};       
    }

    vector<int> SetProcessesQL(int n) {
        int levels;
        cout << "Enter the no of Levels: ";
        cin >> levels;
        // work on the vectored algorithms and then return them
        // see if it has priority. if yes..we have to ask for priority as well

        cout << "\nEnter the Process nos - Arrival Times - Burst Times - Level\t{Eg ::4 5 18 2}" << endl;
        for (int i = 0; i < n; i++) {
            cout << ":: ";
            cin >> ID >> AT >> BT >> QL;
        }
        
        return {ID, AT, BT, PR, QL};       
    }

public:
    vector<int> Run(int choice) {
        int n;
        cout << "Enter the no of Processes: ";
        return SetProcesses(n);
    }
};