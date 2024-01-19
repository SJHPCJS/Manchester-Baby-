#include <iostream>
#include <limits>
#include "ManchesterBaby.cpp"

using namespace std;

int getUserChoice();
void displayMenu();

int main() {

    cout << "\n"
            " ____    ____                         __                    _                ______           __                 \n"
            "|_   \\  /   _|                       [  |                  / |_             |_   _ \\         [  |                \n"
            "  |   \\/   |   ,--.   _ .--.   .---.  | |--.  .---.  .--. `| |-'.---.  _ .--. | |_) |  ,--.   | |.--.   _   __   \n"
            "  | |\\  /| |  `'_\\ : [ `.-. | / /'`\\] | .-. |/ /__\\\\( (`\\] | | / /__\\\\[ `/'`\\]|  __'. `'_\\ :  | '/'`\\ \\[ \\ [  ]  \n"
            " _| |_\\/_| |_ // | |, | | | | | \\__.  | | | || \\__., `'.'. | |,| \\__., | |   _| |__) |// | |, |  \\__/ | \\ '/ /   \n"
            "|_____||_____|\\'-;__/[___||__]'.___.'[___]|__]'.__.'[\\__) )\\__/ '.__.'[___] |_______/ \\'-;__/[__;.__.'[\\_:  /    \n"
            "                                                                                                       \\__.'     " << endl;
    int choice;
    auto manchesterBaby = new ManchesterBaby(new Store(), new Control(), new Accumulator());
    displayMenu();
    choice = getUserChoice();

    // Perform the operation based on user choice
    switch (choice) {
        case 1:
            manchesterBaby->loadProgram();
	    cout << "Normal Termination" << endl;
	    cout << "Shutting down..." << endl;
            break;
        case 2:
            cout << "Shutting down..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
    }

    cout << "Thank you for using the Simulator!" << endl;

    return 0;
}

int getUserChoice() {
    int choice;
    while (true) {
        cout << "Enter your choice (1-2)\n>";
        if (cin >> choice && choice >= 1 && choice <= 2) {
            break;
        } else {
            cout << "Invalid input. Please enter a number between 1 and 2." << endl;
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore last input
        }
    }
    return choice;
}

void displayMenu() {
    cout << "=========== Menu ============" << endl;
    cout << "1. Load program from file" << endl;
    cout << "2. Power off" << endl;
    cout << "=============================" << endl;
}


