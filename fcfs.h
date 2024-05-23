#ifndef FCFS_H
#define FCFS_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class FCFS {
private:
    struct table {
        int num, AT, BT;
        int CT, TAT, WT;
        bool used;

        table(int _num = 0, int _AT = 0, int _BT = 0, bool _used = false)
            : num(_num), AT(_AT), BT(_BT), CT(0), TAT(0), WT(0), used(_used) {}
    };

    vector<table> Input(int n);
    void GanttChart(vector<table>& Process, int n);
    void PrintTable(vector<table>& Process, int n);
    void PrintAverage(vector<table>& Process, int n);

public:
    void execute();
    void ConcurrentExecute(vector<table>& Process);
};

#endif
