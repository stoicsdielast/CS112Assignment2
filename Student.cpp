//Contains the student class
#include "Student.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor
Student::Student(string id, double cw, double fe) : ID(id), courseWork(cw), finalExam(fe) {}

// Getters and setters:
string Student::getID() { 
    return ID;
}
double Student::getCourseWork() { 
    return courseWork; }
double Student::getFinalExam() { 
    return finalExam; }
void Student::setCourseWork(double cw) { 
    courseWork = cw; }
void Student::setFinalExam(double fe) { 
    finalExam = fe; }

// Calculate grade from USP Handbook 2024
string Student::calculateGrade() {
    double totalMarks = courseWork + finalExam;
    if (totalMarks >= 85) return "A+";
    else if (totalMarks >= 78) return "A";
    else if (totalMarks >= 71) return "B+";
    else if (totalMarks >= 64) return "B";
    else if (totalMarks >= 57) return "C+";
    else if (totalMarks >= 50) return "C";
    else return "F";
}

// Display details
void Student::display() {
    double total = courseWork + finalExam;
    cout << setw(10) << ID
        << setw(15) << courseWork
        << setw(15) << finalExam
        << setw(10) << total
        << setw(10) << calculateGrade() << endl;
}
