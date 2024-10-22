//Contains code for input message and other useful code
#include "Utils.h"
#include "LinkedList.h"
#include <iostream>
#include <limits>

using namespace std;

//Display Message
void displayMenu() {
    cout << "\n|-----------------------------------------------------------|\n"
        << "|             A Student Grade Management Program            |\n"
        << "|-----------------------------------------------------------|\n"
        << "|(1) Update Student Mark.                                   |\n"
        << "|(2) Print Enter Student Details.                           |\n"
        << "|(3) Show the average marks.                                |\n"
        << "|(4) Show Pass Rate.                                        |\n"
        << "|(5) Exit the program.                                      |\n"
        << "|-----------------------------------------------------------|\n";
}
//Input:
int getChoice() {
    int choice;
    cout << "Enter the number of your choice: ";
    cin >> choice;
    return choice;
}

string getStudentID() {
    string id;
    cout << "Enter student ID: ";
    cin >> id;
    return id;
}

double getMarks() {
    double marks;
    cout << "Enter marks: ";
    cin >> marks;
    return marks;
}
//else if structure for user choice on desired input
bool handleChoice(int choice) {
    string id;
    double courseWork, finalExam;

    if (choice == 1) {
        id = getStudentID();  // Get student ID
        courseWork = getMarks();  // Get coursework marks
        if (!validateInput(courseWork)) return true;
        finalExam = getMarks();  // Get final exam marks
        if (!validateInput(finalExam)) return true;
        updateMarks(id, courseWork, finalExam);
    }
    else if (choice == 2) {
        printDetails();
    }
    else if (choice == 3) {
        printAverageMarks();
    }
    else if (choice == 4) {
        printPassRate();
    }
    else if (choice == 5) {
        cout << "Exiting the program." << endl;
        return false;  // Return false to stop the program
    }
    else {
        cout << "Invalid choice. Please choose a valid option." << endl;
    }

    // Ask the user whether they want to continue or not
    return askToContinue();  // Return true to continue, false to exit
}

//Asks whether to continue with the program before looping
bool askToContinue() {
    char response;
    cout << "\nDo you want to continue? (y/n): ";
    cin >> response;

    // Validate the response
    if (response == 'y' || response == 'Y') {
        return true;  
    }
    else if (response == 'n' || response == 'N') {
        return false;  
    }
    else {
        cout << "Invalid input.Do you want to continue ? (y / n) :\n";
        return askToContinue();  // Recusively calls to try again
    }
}

//Discards the first line in the .txt file
void discard_line(ifstream& in) {
    char c;
    do {
        in.get(c);
    } while (c != '\n');
} 
// Input validation
bool validateInput(double& input) {
    if (cin.fail() || input < 0 || input > 100) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, please enter a number between 0 and 5." << endl;
        return false;
    }
    return true;
}
