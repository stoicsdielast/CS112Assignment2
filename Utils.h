#ifndef UTILS_H
#define UTILS_H
#include <string>
using namespace std;

#include <fstream>
void displayMenu();
int getChoice();
string getStudentID();
double getMarks();
bool handleChoice(int choice);
bool askToContinue();
void discard_line(std::ifstream& in);
bool validateInput(double& input);

#endif // UTILS_H
