#include <iostream>
#include <vector>
#include <cctype>
#include "GPA_Calculator.h"

using namespace std;

float gradeToPoint(char grade) {
    grade = toupper(grade); // Convert to uppercase using std::toupper
    switch (grade) {
    case 'A': return 4.0;
    case 'B': return 3.0;
    case 'C': return 2.0;
    case 'D': return 1.0;
    case 'F': return 0.0;
    default: return -1.0;  // Invalid grade
    }
}

void calculateGPA() {
    int courses;
    cout << "Enter Number of courses: ";
    cin >> courses; 

    vector<float> credits(courses);
    vector<char> grade(courses);

    float totalCredits = 0.0, GradePoints = 0.0;

    for (int i = 0; i < courses; i++) {
        cout << "\nCourse " << i + 1 << endl;
        while (true) {
            cout << "Enter Grades (A, B, C, D, F): ";
            cin >> grade[i];
            if (gradeToPoint(grade[i]) != -1.0) {
                break; 
            }
            else {
                cout << "Invalid Grade. Please enter A, B, C, D, or F." << endl;
            }
        }
        while (true) {
            cout << "Enter Credits: ";
            cin >> credits[i];
            if (credits[i] > 0) {
                break; 
            }
            else {
                cout << "Invalid Credits. Please enter a positive number." << endl;
            }
        }

        GradePoints += (gradeToPoint(grade[i]) * credits[i]);
        totalCredits += credits[i];
    }

    if (totalCredits > 0) {
        float GPA = GradePoints / totalCredits;
        cout << "GPA = " << GPA << endl;
    }
    else {
        cout << "No credits entered. GPA cannot be calculated." << endl;
    }

    cout << "\nCourse No.\tGrade" << endl;
    for (int i = 1; i <= courses; i++) {
        cout << i << "\t\t" << char(toupper(grade[i - 1])) << "\n"; 
    }
}
