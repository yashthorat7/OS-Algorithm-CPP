#include <iostream>
#include <string>
#include <vector>

#include "cpu_scheduling.h"
#include "HelpManager.h"
#include "input_validator.h"

using namespace std;


class MainMenu {
private:
    void DisplayTitle() const {
        cout << "   ___  ____       _    _     ____  ___  ____  ___ _____ _   _ __  __ ____   \n"
            "  / _ \\/ ___|     / \\  | |   / ___|/ _ \\|  _ \\|_ _|_   _| | | |  \\/  / ___|  \n"
            " | | | \\___ \\    / _ \\ | |  | |  _| | | | |_) || |  | | | |_| | |\\/| \\___ \\  \n"
            " | |_| |___) |  / ___ \\| |__| |_| | |_| |  _ < | |  | | |  _  | |  | |___) | \n"
            "  \\___/|____/  /_/   \\_\\_____\\____|\\___/|_| \\_\\___| |_| |_| |_|_|  |_|____/  \n"
            "                                                           Yash Thorat | C++\n";
    }

    void DisplayHelp() const {
        cout << "This is the help section\nHere we will do everything except helping you\n";
    }

    void HandleChoice(int choice) const {
        switch (choice) {
            case 1:
                CPUScheduling scheduler;
                scheduler.execute();
                break;
            case 2:
                cout << "Disk Scheduling" << endl;
                break;
            case 3:
                cout << "Page Replacement Algorithms" << endl;
                break;
            case 4:
                cout << "Bankers Algorithm" << endl;
                break;
            case 5:
                cout << "Memory Allocation Algorithms" << endl;
                break;
        }
    }

    void DisplayMenu() const {
        cout << "\n1. CPU Scheduling\t\t2. Disk Scheduling\t\t3. Page Replacement\n";
        cout << "4. Bankers Algorithm\t\t5. Memory Allocation\t\t6. Exit\n";
    }

    vector<int> GetMenuChoice() const {
        string choice;
        vector<int> choices;
        InputValidator validator;

        while (true) {
            cout << "\nEnter a choice number: ";
            getline(cin, choice);
            if (choice == "help") {
                DisplayHelp();
                continue;
            } else {
                choices = validator.InputArray(choice);
            }
            if (choices.empty()) {
                cout << "Please enter a valid number! Type \"help\" for assistance.\n";
            }
        }
        return choices;
    }

public:
    inline void Run() {
        DisplayTitle();

        while (true) {
            DisplayMenu();
            vector<int> choice = GetMenuChoice();
            if (choice[0] == 6) {
                cout << "\nThank you!" << endl;
                break;
            }
            for (auto choiceInt: choice)
                HandleChoice(choiceInt);
        }
    }
};

int main() {
    MainMenu app;
    app.Run();
    return 0;
}
