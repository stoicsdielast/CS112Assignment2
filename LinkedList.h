#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Student.h"
//#include "Utils.h"

struct NODE {
    NODE* pNext;
    NODE* pPrev;
    Student* student;

    NODE(Student* s);
};

// Linked list functions
void appendNode(Student* s);
void removeNode(NODE* pNode);
void deleteAllNodes();
void printDetails();
void printAverageMarks();
void printPassRate();
void updateMarks(const std::string& id, double courseWork, double finalExam);
void readData(const std::string& filename);
//void discard_line(ifstream& in);
#endif // LINKEDLIST_H
