#include <iostream>
#include <string>
#include "CPUScheduling.cpp"

using namespace std;

class MainMenu {
public:
    void Run() {
        DisplayTitle();

        while (true) {
            DisplayMenu();
            int choice = GetMenuChoice();
            if (choice == 6) {
                cout << "\nThank you!" << endl;
                break;
            }
            HandleChoice(choice);
        }
    }

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
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    void DisplayMenu() const {
        cout << "\n1. CPU Scheduling\t\t2. Disk Scheduling\t\t3. Page Replacement\n";
        cout << "4. Bankers Algorithm\t\t5. Memory Allocation\t\t6. Exit\n";
    }

    int GetMenuChoice() const {
        string choice;
        InputValidator validator;

        while (true) {
            cout << "\nEnter a choice number: ";
            getline(cin, choice);
            if (choice == "help") {
                DisplayHelp();
                continue;
            }

            if (validator.CheckValid(choice, 6)) {
                int choiceInt = stoi(choice);
                if (choiceInt == 6) {
                    return choiceInt;
                }
                return choiceInt;
            } else {
                cout << "Please enter a valid number! Type \"help\" for assistance.\n";
            }
        }
    }
};

int main() {
    MainMenu app;
    app.Run();
    return 0;
}
