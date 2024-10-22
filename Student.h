#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string ID;
    double courseWork;
    double finalExam;

public:
    // Constructor
    Student(std::string id, double cw, double fe);

    // Getters and setters
    std::string getID();
    double getCourseWork();
    double getFinalExam();
    void setCourseWork(double cw);
    void setFinalExam(double fe);

    
    std::string calculateGrade();
    void display();
};

#endif // STUDENT_H
