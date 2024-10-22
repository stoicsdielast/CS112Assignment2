//Contains all implementation for LinkLists
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Utils.h"

using namespace std;

NODE* pHead = NULL;
NODE* pTail = NULL;

NODE::NODE(Student* s) : student(s), pNext(NULL), pPrev(NULL) {}

// reads data and stores it in LinkList
void readData(const string& filename) {
    ifstream input(filename.c_str());
    if (!input) {
        cerr << "File could not be opened" << endl;
        exit(1);
    }

    discard_line(input);// removes the first line

    string id;
    double courseWork, finalExam;
    while (input >> id >> courseWork >> finalExam) {
        Student* s = new Student(id, courseWork, finalExam);
        appendNode(s);
    }

    input.close();
}

// Append a new node to the end of the linked list
void appendNode(Student* s) {
    NODE* pNode = new NODE(s);
    if (pHead == NULL) { // If the list is empty
        pHead = pNode; // The new node is both the head and tail
    }
    else {
        pTail->pNext = pNode; // Link the current tail's next to the new node
        pNode->pPrev = pTail; // Set the new node's previous to the current tail
    }
    pTail = pNode; // Update the tail to the new node
}

// Removes node
void removeNode(NODE* pNode) {
    if (pNode->pPrev == NULL) { // If the node is the head
        pHead = pNode->pNext; // Move the head to the next node
    }
    else {
        pNode->pPrev->pNext = pNode->pNext; // Bypass the node
    }

    if (pNode->pNext == NULL) { // If the node is the tail
        pTail = pNode->pPrev; // Move the tail to the previous node
    }
    else {
        pNode->pNext->pPrev = pNode->pPrev; // Bypass the node
    }

    delete pNode->student; // Free the memory allocated for the student
    delete pNode; // Free the node itself
}

// Delete all nodes from the list
void deleteAllNodes() {
    while (pHead != NULL) {
        removeNode(pHead); // Continuously remove the head node until the list is empty
    }
}

// Update student marks
void updateMarks(const string& id, double courseWork, double finalExam) {
    NODE* pNode = pHead;
    while (pNode != NULL) {
        if (pNode->student->getID() == id) {
            pNode->student->setCourseWork(courseWork);
            pNode->student->setFinalExam(finalExam);
            cout << "Marks updated successfully." << endl;
            return;
        }
        pNode = pNode->pNext;
    }
    cout << "Student ID not found." << endl;// Input Validation
}

// Print all student details
void printDetails() {
    cout << "--------------------------------------------------------------\n";
    cout << "    ID          Coursework    Final Exam     Total      Grade" << endl;
    cout << "--------------------------------------------------------------\n";
    NODE* pNode = pHead;
    while (pNode != NULL) {
        pNode->student->display(); // Display each student's details
        pNode = pNode->pNext;
    }
}

// Print the average marks of all students
void printAverageMarks() {
    double totalMarks = 0.0;
    int count = 0;
    NODE* pNode = pHead;

    while (pNode != NULL) {
        totalMarks += pNode->student->getCourseWork() + pNode->student->getFinalExam();
        count++;
        pNode = pNode->pNext;
    }

    double avgMarks = (count > 0) ? totalMarks / count : 0.0;
    cout << "\nAverage Marks: " << fixed << setprecision(2) << avgMarks << endl;
}

// Print the pass rate of students
void printPassRate() {
    int passCount = 0;
    int count = 0;
    NODE* pNode = pHead;

    while (pNode != NULL) {
        double total = pNode->student->getCourseWork() + pNode->student->getFinalExam();
        string grade = pNode->student->calculateGrade();
        if (grade != "F") passCount++;
        count++;
        pNode = pNode->pNext;
    }

    double passRate = (count > 0) ? (static_cast<double>(passCount) / count) * 100 : 0.0;
    cout << "Pass Rate: " << fixed << setprecision(2) << passRate << "%" << endl;
}
