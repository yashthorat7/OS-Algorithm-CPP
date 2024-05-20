#include <iostream>
#include <string>
#include <vector>

#include "input_validator.h"
#include "fcfs.cpp"

using namespace std;

class CPUScheduling {
private:
    bool HasPriority(const vector<int>& choices) const {
        for (auto choice : choices) {
            if (choice == 4 || choice == 5) {
                return true;
            }
        }
        return false;
    }

    void CollectProcessDetails(int n, bool hasPriority, vector<int>& processList) const {
        cout << "\nEnter the Process numbers - Arrival Times - Burst Times";
        if (hasPriority)
            cout << " - Priority (low > high) {Eg: 1 4 11 2}\n";
        else 
            cout << " {Eg: 4 1 2}\n";

        for (int i = 0; i < n; i++) {
            int process;
            cout << ":: ";
            //cin >> process.num >> process.AT >> process.BT;
            //if (hasPriority)
            //    cin >> process.PR;
            processList.push_back(process);
        }
    }

    bool CollectProcess(const vector<int>& choices, vector<int>& processList) {
        int n = choices.size();
        if (n == 1)
            return false;

        bool hasPriority = HasPriority(choices);

        cout << "Enter the number of Processes: ";
        cin >> n;

        CollectProcessDetails(n, hasPriority, processList);
        
        return true;
    }

    void HandleChoice(int choice, vector<int>& processList) {
        int n = processList.size();
        switch (choice) {
            case 1:
                cout << "Executing FCFS...\n";
                FCFS fcfs;
                if (n < 1) fcfs.execute();
                break;
            case 2:
                cout << "case 2";
                break;
            case 3:
                cout << "case 3";
                break;
            case 4:
                cout << "case 4";
                break;
            case 5:
                cout << "case 5";
                break;
            case 6:
                cout << "case 6";
                break;
            case 7:
                cout << "yet to add this feature";
                break;
        }
        cout << endl;
    }

    void DisplayMenu() const {
        cout << "\n1. FCFS\t\tFirst Come First Serve\n2. SJF NP\tShortest Job First (Non Preemptive)\n";
        cout << "3. SJF P\tShortest Job First (Preemptive)\n4. PRI NP\tPriority Based Queue (Non Preemptive)\n";
        cout << "5. PRI P\tPriority Based Queue (Preemptive)\n6. RR\t\tRound Robin\n";
        cout << "7. *MLQ\t\tMultiLevel Queue\n8. Back";
    }

    vector<int> GetMenuChoices() const {
        string choice;
        vector<int> choices;
        InputValidator validator;

        while (true) {
            cout << "\nEnter a choice number: ";
            getline(cin, choice);
            if (choice == "help") {
                cout << "Help!";    //add help here
                continue;
            } else {
                choices = validator.InputArray(choice);
            }
            if (choices.empty()) {
                cout << "Please enter a valid number! Type \"help\" for assistance.\n";
            } else {
                break;
            }
        }
        return choices;
    }

public:
    void Run() {
        DisplayMenu();
        vector<int> processList;
        vector<int> choices = GetMenuChoices();

        CollectProcess(choices, processList);
        for (auto choice: choices) {
            HandleChoice(choice, processList);
        }
    }
};