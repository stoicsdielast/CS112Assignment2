#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 20;  // Maximum number of students

class Student {
public:
    string ID;
    double courseWork;
    double finalExam;
};

void readData(Student students[], int& total_records);
char calculateGrade(double totalMarks);
void printDetails(Student students[], int total_records);
void discard_line(ifstream& in);
void updateMarks(Student students[], int total_records, string id, double courseWork, double finalExam);

int main() {
    Student students[MAX_SIZE];
    int total_records = 0;  // Initialize to 0
    int choice;
    string id;
    double courseWork, finalExam;

    readData(students, total_records);

    do {
        cout << "|-----------------------------------------------------------|\n";
        cout << "|             A Student Grade Calculator Program            |\n";
        cout << "|-----------------------------------------------------------|\n";
        cout << "Program Menu Tab:" << endl
             << "(1) Update Student Mark." << endl
             << "(2) Print Enter Student Details." << endl
             << "(3) Exit the Program" << endl;

        cout << "Enter the number of your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter new coursework marks: ";
            cin >> courseWork;
            cout << "Enter new final exam marks: ";
            cin >> finalExam;
            updateMarks(students, total_records, id, courseWork, finalExam);
        }
        else if (choice == 2) {
            printDetails(students, total_records);
        }
    } while (choice != 3);

    return 0;
}

void readData(Student students[], int& total_records) {
    ifstream input("studentData.txt");
    if (!input) {
        cerr << "File could not be opened" << endl;
        exit(1);
    }

    discard_line(input);

    while (input >> students[total_records].ID >> students[total_records].courseWork >> students[total_records].finalExam) {
        total_records++;
        if (total_records >= MAX_SIZE) {
            cout << "Maximum student records reached!" << endl;
            break;
        }
    }

    input.close();
}

void discard_line(ifstream &in) {
    char c;
    do {
        in.get(c);
    } while (c != '\n');
}

char calculateGrade(double totalMarks) {
    if (totalMarks >= 85) return 'A+';
    else if (totalMarks >= 78) return 'A';
    else if (totalMarks >= 71) return 'B+';
    else if (totalMarks >= 64) return 'B';
    else if (totalMarks >= 57) return 'C+';
    else if (totalMarks >= 50) return 'C';
    else return 'F';
}

void updateMarks(Student students[], int total_records, string id, double courseWork, double finalExam) {
    for (int i = 0; i < total_records; i++) {
        if (students[i].ID == id) {
            students[i].courseWork = courseWork;
            students[i].finalExam = finalExam;
            cout << "Marks updated successfully." << endl;
            return;
        }
    }
    cout << "Student ID not found." << endl;
}

void printDetails(Student students[], int total_records) {
    double totalMarks = 0.0;
    int passCount = 0;
    Student topStudent = students[0];

    cout << setw(10) << "ID" << setw(15) << "Coursework" << setw(15) << "Final Exam" << setw(10) << "Total" << setw(10) << "Grade" << endl;
    for (int i = 0; i < total_records; i++) {
        double total = students[i].courseWork + students[i].finalExam;  // Corrected typo
        char grade = calculateGrade(total);
        totalMarks += total;
        if (grade != 'F') passCount++;
        if (total > (topStudent.courseWork + topStudent.finalExam)) {  // Corrected typo
            topStudent = students[i];
        }
        cout << setw(10) << students[i].ID << setw(15) << students[i].courseWork << setw(15) << students[i].finalExam << setw(10) << total << setw(10) << grade << endl;
    }
    double avgMarks = totalMarks / total_records;
    double passRate = (double)passCount / total_records * 100;

    cout << "\nAverage Marks: " << fixed << setprecision(2) << avgMarks << endl;
    cout << "Pass Rate: " << fixed << setprecision(2) << passRate << "%" << endl;
    cout << "Top Scorer: " << topStudent.ID << " with " << topStudent.courseWork + topStudent.finalExam << " marks." << endl;
}

