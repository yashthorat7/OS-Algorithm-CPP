#include <iostream>
#include <string>
#include "CPUScheduling.cpp"

using namespace std;

void Help() {
    cout << "This is the help section\nHere we will do everything except helping you\n";
}

void GoCase(int choice) {
    switch(choice) {
        case 1: CPUScheduling scheduler;
            scheduler.execute();
            break;
        case 2: cout << "Disk Scheduling";
            break;
        case 3: cout << "Page Replacement Algorithms";
            break;
        case 4: cout << "Bankers Algorithm";
            break;
        case 5: cout << "Memory Allocation Algorithms";
            break;
    }
}

int PrintMenu() {
    string choice;
    InputValidator obj;

    cout << "\n1. CPU Scheduling\t\t2. Disk Scheduling\t\t3. Page Replacement\n";
    cout << "4. Bankers Algorithm\t\t5. Memory Allocation\t\t6. Exit\n";

    do {
        cout << "\nEnter a choice no: ";
        getline(cin, choice);
        if (choice == "help") {
            Help();
            continue;
        }
        if (stoi(choice) == 6)
            return {6};
         
        
        if(!obj.CheckValid(choice, 6))
            cout << "Please enter a valid no! type \"help\"\n";

    } while (!obj.CheckValid(choice, 6));

    return stoi(choice);
}

void PrintTitle() {
    cout << "   ___  ____       _    _     ____  ___  ____  ___ _____ _   _ __  __ ____   \n"
        "  / _ \\/ ___|     / \\  | |   / ___|/ _ \\|  _ \\|_ _|_   _| | | |  \\/  / ___|  \n" 
        " | | | \\___ \\    / _ \\ | |  | |  _| | | | |_) || |  | | | |_| | |\\/| \\___ \\  \n" 
        " | |_| |___) |  / ___ \\| |__| |_| | |_| |  _ < | |  | | |  _  | |  | |___) | \n"
        "  \\___/|____/  /_/   \\_\\_____\\____|\\___/|_| \\_\\___| |_| |_| |_|_|  |_|____/  \n"
        "                                                           Yash Thorat | C++\n";
}

int main() {
    PrintTitle();

    while (true) {
        int choice = PrintMenu();
        if (choice == 6) return 0;
        GoCase(choice);
    }
    cout << "\nThank-You";

    return 0;
}