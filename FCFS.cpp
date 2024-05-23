#include "FCFS.h"
#include <climits>
#include <iostream>

using namespace std;

vector<FCFS::table> FCFS::Input(int n) {
    vector<table> Process;
    cout << "\nEnter the Process nos - Arrival Times - Burst Times\t{Eg ::4 5 18}" << endl;
    for (int i = 0; i < n; i++) {
        table process;
        cout << ":: ";
        cin >> process.num >> process.AT >> process.BT;
        Process.push_back(process);
    }

    return Process;
}

void FCFS::GanttChart(vector<table>& Process, int n) {
    cout << endl << "Gantt Chart:" << endl << endl;
    int clock = 0;

    for (int executed = 0; executed < n; executed++) {
        int minAT = INT_MAX, minIndex = 0;
        for (int i = 0; i < n; i++) {
            if (Process[i].AT < minAT && !Process[i].used)
                minAT = Process[i].AT, minIndex = i;
        }
        Process[minIndex].used = true;

        if (clock == 0) {
            cout << "| ";
        }
        if (Process[minIndex].AT > clock) {
            cout << clock << " | - | ";
            clock = Process[minIndex].AT;
        }
        cout << clock << " | P" << Process[minIndex].num << " | ";
        clock += Process[minIndex].BT;
        Process[minIndex].CT = clock;
    }
    cout << clock << " |" << endl;
}

void FCFS::PrintTable(vector<table>& Process, int n) {
    cout << endl << "Table: " << endl << endl;
    cout << "ID\tAT\tBT\tCT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++) {
        int ArrivalTime = (Process[i].AT < 0) ? 0 : Process[i].AT;
        Process[i].TAT = Process[i].CT - ArrivalTime;
        Process[i].WT = Process[i].TAT - Process[i].BT;
        cout << "P" << Process[i].num << "\t" << Process[i].AT << "\t" << Process[i].BT;
        cout << "\t" << Process[i].CT << "\t" << Process[i].TAT << "\t" << Process[i].WT;
        cout << endl;
    }
}

void FCFS::PrintAverage(vector<table>& Process, int n) {
    float sumTAT = 0, sumWT = 0;
    for (int i = 0; i < n; i++) {
        sumTAT += Process[i].TAT;
        sumWT += Process[i].WT;
    }
    cout << "\nAverage Turn Around Time: " << setprecision(2) << sumTAT / n << endl;
    cout << "Average Waiting Time: " << setprecision(2) << sumWT / n;
}

void FCFS::execute() {
    int n;
    cout << endl;
    cout << "Enter the number of Processes: ";
    cin >> n;
    vector<table> Process = Input(n);
    GanttChart(Process, n);
    PrintTable(Process, n);
    PrintAverage(Process, n);
}

void FCFS::ConcurrentExecute(vector<table>& Process) {
    vector<table> newProcess;
    for (auto& p : Process) {
        newProcess.push_back(table(p.num, p.AT, p.BT, p.used));
    }
    int n = newProcess.size();
    GanttChart(newProcess, n);
    PrintAverage(newProcess, n);
}