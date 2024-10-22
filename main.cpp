/*  CS112: Data Structures & Algorithms,
    Assignment 2 – Semester II, 2024,
    A Student Grade Calculator Program.


    Group Partner Names & Id:
    Parvish Mohan - s11230414
    Tanzeel Hussain - s11230375

    Campus: Laucala, Suva, Fiji.
    Mode: F.
*/
#include "Student.h"
#include "LinkedList.h"
#include "Utils.h"
#include <iostream>

using namespace std;

int main() {
    readData("studentData.txt");

    int choice;
    string id;
    bool keepRunning = true;
    double courseWork, finalExam;
    bool handleChoice(int choice);

    while (keepRunning) {
        displayMenu();  // Display the menu
        choice = getChoice();  // Get the user's choice
        keepRunning = handleChoice(choice);  // Handles user's choice while having the option to end the loop
    }

    deleteAllNodes();// frees up memory



    return 0;
}
