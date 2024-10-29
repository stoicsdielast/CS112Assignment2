|-----------------------------------------------------------|
|             A Student Grades Management Program           |
|-----------------------------------------------------------|
By: -Parvish Mohan  (s11230414)
    -Tanzeel Hussain (s11230375)

Overview:

The program has been successfully transitioned from using arrays of structs to utilizing linked lists of class objects. Here’s an overview of the key aspects and advantages of this approach:
Key Features:
Dynamic Sizing:
        The linked list allows for dynamic memory allocation, meaning it can grow and shrink as needed. This eliminates the limitations of fixed-size arrays, providing flexibility in managing student data.

Object-Oriented Programming:
        By using classes instead of structs, the program leverages the principles of object-oriented programming (OOP). This includes encapsulation, inheritance (if applicable), and polymorphism, leading to a 	more modular and organized codebase.

Modularity:
        The use of classes allows for better organization of code into reusable components. Each class can contain its own methods and data, making it easier to manage complex functionalities related to student 	records, such as updating marks, calculating grades, and displaying information.

Improved Data Management:
        The linked list structure facilitates easier insertion and deletion of student records. New students can be added without the need for shifting elements, and records can be removed efficiently.

Enhanced Readability and Maintenance:
        Code that utilizes classes is often more readable, as it allows for meaningful names and structures. This enhances maintainability and reduces the likelihood of errors during updates or modifications.

Files:
	main.cpp: The main source code file.
	LinkedList.cpp: containing implementation of the LinkedList.h as the header file.
	Student.cpp: Contains the student class with student.h as the header.
	Utils.cpp: the user interface utilities for user experience for the application with its header file  
	studentData.txt: A text file containing the student data (ID, coursework marks, final 	exam marks).

Features:
 	Reading Data: Reads student records from a text file.
 	Grade Calculation: Calculates grades based on the total marks (coursework + final 	exam) from the University of the South Pacific's Handbook 2024.
 	Update Functionality: Allows the user to update a student's marks by their ID.
 	Printing Details: Displays all student records, average marks, pass rate, and the top 	scorer's details.

HOW TO RUN:
Prerequisites:

    A C++ compiler (such as g++, clang, or MSVC).
    The program was tested using Dev-C++ 4.9.9

Compiling the Program:
	To compile the program, use the following command in your terminal or command prompt:
	g++ -o gradeStudents main.cpp

Running the Program
	After compiling, run the program using:
	./gradeStudents

For windows run after compilation from an IDE:
	gradeStudents.exe

Or, Compile and Run using Visual Studio 2022
	Open the StudentGradeManagement.sln file and debug.


Ensure that the first line of the file contains headers and the actual data starts from the second line which would ensure the program is reading data correctly.

Upon running, the program will offer the following menu options:
	Update Marks: Allows you to update the marks of a student by entering their ID, new coursework marks, and final exam marks.
	Print Details: Details, Pass rate, Average Mark and details of the top scorer.
	Exit: Exits the program.

Have a wonderful day to the person reading this! Hope you love our program, do give us a feedback for us to improve on our program for the best user experience, thank you. 
