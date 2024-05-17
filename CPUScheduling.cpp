#include <iostream>
#include <string>
#include <vector>
#include "InputValidator.cpp"
#include "FCFS.cpp"
#include "SJF_NP.cpp"
#include "SJF_P.cpp"
#include "PRI_NP.cpp"
#include "PRI_P.cpp"
#include "RR.cpp"
#include "MLQ.cpp"
using namespace std;

class CPUScheduling {
    struct table {
        int num, AT, BT, PR;
        int CT, TAT, WT;
        bool used;

        table(int _PR = 0, bool _used = false) : PR(_PR), used(_used) {}
    };

private:
    void Help() {
        cout << "Hi";
    }

    void GoCases(int choice) {
        switch(choice) {
            case 1: FCFS fcfs;
                    fcfs.execute();
                    break;
            case 2: cout << "case 2"; break;
            case 3: cout << "case 3"; break;
            case 4: cout << "case 4"; break;
            case 5: cout << "case 5"; break;
            case 6: cout << "case 6"; break;
            case 7: cout << "yet to add this feature"; break;
        }
        cout << endl;
    }

    vector<int> PrintMenu() {
        string choice;
        InputValidator obj;

        cout << "\n1. FCFS\t\tFirst Come First Serve\n2. SJF NP\tShortest Job First (Non Preemptive)\n";
        cout << "3. SJF P\tShortest Job First (Preemptive)\n4. PRI NP\tPriority Based Queue (Non Preemptive)\n";
        cout << "5. PRI P\tPriority Based Queue (Preemptive)\n6. RR\t\tRound Robin\n";
        cout << "7. *MLQ\t\tMultiLevel Queue\n";

        vector<int> Choices;
        int n;
        do {
            cout << "\nEnter a choice nos: ";
            getline(cin, choice);
            if (choice == "help") {
                Help();
                continue;
            }
            if (stoi(choice) == 8)
                return {8};
            Choices = obj.InputArray(choice, 7);
            
            if(Choices.empty())
                cout << "Please enter a valid no! type \"help\"\n";

        } while (Choices.empty());

        return Choices;
    }

public:
    void execute() {
        vector<int> choices = PrintMenu(); 
        for (auto choice: choices) {
            GoCases(choice);
        }
    }
};