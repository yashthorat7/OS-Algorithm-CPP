#include "FCFS.h"
#include <climits>
#include <iostream>

std::vector<FCFS::table> FCFS::Input(int n) {
    std::vector<table> Process;
    std::cout << "\nEnter the Process nos - Arrival Times - Burst Times\t{Eg ::4 5 18}" << std::endl;
    for (int i = 0; i < n; i++) {
        table process;
        std::cout << ":: ";
        std::cin >> process.num >> process.AT >> process.BT;
        Process.push_back(process);
    }

    return Process;
}

void FCFS::GanttChart(std::vector<table>& Process, int n) {
    std::cout << std::endl << "Gantt Chart:" << std::endl << std::endl;
    int clock = 0;

    for (int executed = 0; executed < n; executed++) {
        int minAT = INT_MAX, minIndex = 0;
        for (int i = 0; i < n; i++) {
            if (Process[i].AT < minAT && !Process[i].used)
                minAT = Process[i].AT, minIndex = i;
        }
        Process[minIndex].used = true;

        if (clock == 0) {
            std::cout << "| ";
        }
        if (Process[minIndex].AT > clock) {
            std::cout << clock << " | - | ";
            clock = Process[minIndex].AT;
        }
        std::cout << clock << " | P" << Process[minIndex].num << " | ";
        clock += Process[minIndex].BT;
        Process[minIndex].CT = clock;
    }
    std::cout << clock << " |" << std::endl;
}

void FCFS::PrintTable(std::vector<table>& Process, int n) {
    std::cout << std::endl << "Table: " << std::endl << std::endl;
    std::cout << "ID\tAT\tBT\tCT\tTAT\tWT" << std::endl;
    for (int i = 0; i < n; i++) {
        int ArrivalTime = (Process[i].AT < 0) ? 0 : Process[i].AT;
        Process[i].TAT = Process[i].CT - ArrivalTime;
        Process[i].WT = Process[i].TAT - Process[i].BT;
        std::cout << "P" << Process[i].num << "\t" << Process[i].AT << "\t" << Process[i].BT;
        std::cout << "\t" << Process[i].CT << "\t" << Process[i].TAT << "\t" << Process[i].WT;
        std::cout << std::endl;
    }
}

void FCFS::PrintAverage(std::vector<table>& Process, int n) {
    float sumTAT = 0, sumWT = 0;
    for (int i = 0; i < n; i++) {
        sumTAT += Process[i].TAT;
        sumWT += Process[i].WT;
    }
    std::cout << "\nAverage Turn Around Time: " << std::setprecision(2) << sumTAT / n << std::endl;
    std::cout << "Average Waiting Time: " << std::setprecision(2) << sumWT / n;
}

void FCFS::execute() {
    int n;
    std::cout << std::endl;
    std::cout << "Enter the number of Processes: ";
    std::cin >> n;
    std::vector<table> Process = Input(n);
    GanttChart(Process, n);
    PrintTable(Process, n);
    PrintAverage(Process, n);
}

void FCFS::ConcurrentExecute(std::vector<table>& Process) {
    std::vector<table> newProcess;
    for (auto& p : Process) {
        newProcess.push_back(table(p.num, p.AT, p.BT, p.used));
    }
    int n = newProcess.size();
    GanttChart(newProcess, n);
    PrintAverage(newProcess, n);
}